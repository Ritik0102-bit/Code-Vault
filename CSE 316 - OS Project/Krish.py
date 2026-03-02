import tkinter as tk
from tkinter import ttk, scrolledtext
import threading
import queue
import time
import random
from datetime import datetime
import math
import platform
import subprocess
import shutil
from collections import deque

# --- Configuration and Styling ---
COLOR_BG_DARK = "#050510"
COLOR_BG_PANEL = "#1a1a2e"
COLOR_NEON_BLUE = "#00e5ff"
COLOR_NEON_PURPLE = "#ff00e5"
COLOR_NEON_ORANGE = "#ff9900"
COLOR_NEON_GREEN = "#00ff8c"
COLOR_TEXT_LIGHT = "#e0e0e0"

ATTACK_SIMULATION_INTERVAL = 0.28
MAX_THREAT_LEVEL = 100
COLOR_METER_SHELL = "#333355"
COLOR_ABORT_BG = "#331a00"

DEFAULT_PARTICLE_COUNT = 24
MAX_THREAT_HISTORY = 60  # For the sparkline graph

# --- ENHANCEMENT: Centralized Color Map ---
THREAT_COLOR_MAP = {
    'LOW': {'level': 0, 'color': COLOR_NEON_BLUE},
    'MEDIUM': {'level': 30, 'color': COLOR_NEON_ORANGE},
    'HIGH': {'level': 70, 'color': COLOR_NEON_PURPLE},
}


# --- Helper: Linear Color Interpolation (RGB Lerp) ---
def hex_to_rgb(hex_color):
    """Converts a hex color string to an RGB tuple (r, g, b)."""
    hex_color = hex_color.lstrip('#')
    return tuple(int(hex_color[i:i + 2], 16) for i in (0, 2, 4))


def rgb_to_hex(r, g, b):
    """Converts an RGB tuple (r, g, b) to a hex color string."""
    # Ensure values are within 0-255 range and are integers
    r, g, b = int(max(0, min(255, r))), int(max(0, min(255, g))), int(max(0, min(255, b)))
    return f'#{r:02x}{g:02x}{b:02x}'


def lerp_color(color1_hex, color2_hex, ratio):
    """Linearly interpolates between two hex colors based on ratio (0.0 to 1.0)."""
    r1, g1, b1 = hex_to_rgb(color1_hex)
    r2, g2, b2 = hex_to_rgb(color2_hex)

    r = r1 + (r2 - r1) * ratio
    g = g1 + (g2 - g1) * ratio
    b = b1 + (b2 - b1) * ratio

    return rgb_to_hex(r, g, b)


def get_threat_color(level: int) -> str:
    """Returns the primary color based on the current threat level."""
    if level < THREAT_COLOR_MAP['MEDIUM']['level']:
        return THREAT_COLOR_MAP['LOW']['color']
    elif level < THREAT_COLOR_MAP['HIGH']['level']:
        return THREAT_COLOR_MAP['MEDIUM']['color']
    else:
        return THREAT_COLOR_MAP['HIGH']['color']


# --- ATTACK_DATA (Unchanged) ---
ATTACK_DATA = {
    "buffer_overflow": {
        "verdict": "Critical buffer overflow detected and mitigated. Memory integrity compromised briefly.",
        "prevention": [
            "Implement Bounds Checking: Ensure all memory writes are within allocated buffer limits.",
            "Use Safe Functions: Utilize secure alternatives to `strncpy`, `snprintf`, etc.",
            "Enable ASLR & DEP: Address Space Layout Randomization (ASLR) and Data Execution Prevention (DEP).",
        ],
        "logs": [
            ("INFO", "Initializing buffer overflow simulation..."),
            ("INFO", "Attempting to write beyond allocated buffer in target process."),
            ("WARNING", "Memory allocation violation detected. System trying to recover."),
            ("ERROR", "Stack frame overwritten. Return address manipulation detected."),
            ("CRITICAL", "Arbitrary code execution attempt prevented!"),
            ("INFO", "Buffer overflow exploit contained. System integrity check initiated."),
            ("INFO", "Simulation completed.")
        ]
    },
    "trapdoor_activation": {
        "verdict": "Covert trapdoor activation attempt detected and neutralized. Backdoor access denied.",
        "prevention": [
            "Supply Chain Security: Vet third-party components for hidden backdoors.",
            "Integrity Monitoring: Implement file integrity monitoring (FIM).",
            "Network Segmentation: Isolate critical systems to limit blast radius.",
        ],
        "logs": [
            ("INFO", "Activating trapdoor simulation..."),
            ("INFO", "Attempting to bypass authentication via hidden entry point."),
            ("WARNING", "Unusual network traffic originating from internal subnet."),
            ("ERROR", "Suspicious API call detected from unprivileged user context."),
            ("CRITICAL", "Backdoor attempt identified and blocked at the kernel level!"),
            ("INFO", "Trapdoor access denied. Malicious connection terminated."),
            ("INFO", "Simulation completed.")
        ]
    },
    "privilege_escalation": {
        "verdict": "Privilege escalation attempt identified and thwarted. Unauthorized access prevented.",
        "prevention": [
            "Principle of Least Privilege: Grant minimal permissions.",
            "Patch Management: Keep OS and apps up-to-date.",
            "Secure Configuration: Disable unnecessary services.",
        ],
        "logs": [
            ("INFO", "Starting privilege escalation simulation..."),
            ("INFO", "Attempting to exploit a local vulnerability to gain root access."),
            ("WARNING", "Unauthorized access attempt to system critical files detected."),
            ("ERROR", "Process running with elevated privileges without justification."),
            ("CRITICAL", "Kernel security module blocked privilege escalation!"),
            ("INFO", "Elevation attempt contained. Attacker's session terminated."),
            ("INFO", "Simulation completed.")
        ]
    },
    "kernel_memory_corruption": {
        "verdict": "Kernel-level memory corruption attack detected and contained. System stability maintained.",
        "prevention": [
            "Kernel Hardening: KASLR and SMEP/SMAP.",
            "Secure Drivers: Ensure drivers are signed and up-to-date.",
            "Memory Safety Languages: Use memory-safe languages for critical modules when possible.",
            "Regular Security Updates: Apply OS patches diligently.",
        ],
        "logs": [
            ("INFO", "Initiating kernel memory corruption simulation..."),
            ("INFO", "Attempting to corrupt kernel data structures via module injection."),
            ("WARNING", "Suspicious memory write operation detected in kernel space."),
            ("ERROR", "Kernel panic avoided by advanced memory protection unit."),
            ("CRITICAL", "Malicious code attempting to write to read-only kernel memory!"),
            ("INFO", "Kernel memory integrity restored. Attack vector identified."),
            ("INFO", "System health check passed. No critical services affected."),
            ("INFO", "Simulation completed.")
        ]
    },
    "cache_poisoning": {
        "verdict": "DNS cache poisoning attack detected and remediated. Malicious resolution prevented.",
        "prevention": [
            "DNSSEC Implementation: Deploy DNS Security Extensions (DNSSEC).",
            "Rate Limiting: Implement rate limiting on DNS queries.",
            "Randomized Source Ports: Use random source ports for DNS queries.",
            "Secure DNS Servers: Use reputable DNS resolvers.",
        ],
        "logs": [
            ("INFO", "Initiating cache poisoning simulation..."),
            ("INFO", "Sending crafted DNS responses to target resolver."),
            ("WARNING", "Abnormal number of DNS queries detected for critical domains."),
            ("ERROR", "Spoofed DNS records injected into local cache!"),
            ("CRITICAL", "DNSSEC validation failed! Malicious entry purged from cache."),
            ("INFO", "Cache poisoning attempt neutralized. DNS services restored."),
            ("INFO", "Reviewing DNS server configuration for vulnerabilities."),
            ("INFO", "Simulation completed.")
        ]
    },
    "side_channel_timing": {
        "verdict": "Side-channel timing leakage detected. Sensitive operations randomized.",
        "prevention": [
            "Constant-time Algorithms: Use algorithms that doesn't leak timing info.",
            "Noise Injection: Add jitter to reduce signal-to-noise ratio.",
            "Hardware Countermeasures: Use hardware features to isolate sensitive tasks.",
        ],
        "logs": [
            ("INFO", "Starting side-channel timing analysis..."),
            ("WARNING", "Abnormal timing variations observed on crypto operations."),
            ("ERROR", "High-resolution timer usage detected in untrusted process."),
            ("CRITICAL", "Potential key exfiltration channel identified and throttled!"),
            ("INFO", "Mitigation: Randomized scheduling enabled."),
            ("INFO", "Simulation completed.")
        ]
    },
    "supply_chain_poisoning": {
        "verdict": "Supply chain compromise detected during dependency verification. Reverted to known-good build.",
        "prevention": [
            "Artifact Signing: Verify signatures for third-party components.",
            "Reproducible Builds: Ensure builds are reproducible and auditable.",
            "Dependency Auditing: Regularly scan and pin versions.",
        ],
        "logs": [
            ("INFO", "Running dependency integrity checks..."),
            ("WARNING", "Unexpected checksum mismatch for vendor package."),
            ("ERROR", "Unsigned module fetched from remote registry!"),
            ("CRITICAL", "Malicious payload in dependency identified and quarantined!"),
            ("INFO", "Restored pinned versions from secure cache."),
            ("INFO", "Simulation completed.")
        ]
    }
}


# --- ENHANCEMENT: App State Manager ---
class AppState:
    """Manages the central state of the application for decoupled access."""

    def __init__(self, master):
        self.master = master
        self._threat_level = tk.IntVar(value=0)
        self._is_running = tk.BooleanVar(value=False)
        self.threat_history = deque([0] * MAX_THREAT_HISTORY, maxlen=MAX_THREAT_HISTORY)

    @property
    def threat_level(self) -> int:
        return self._threat_level.get()

    @threat_level.setter
    def threat_level(self, value: int):
        level = max(0, min(MAX_THREAT_LEVEL, value))
        self._threat_level.set(level)
        self.threat_history.append(level)
        # ENHANCEMENT: Broadcast state change via virtual event
        self.master.event_generate('<<ThreatLevelUpdate>>')

    @property
    def is_running(self) -> bool:
        return self._is_running.get()

    @is_running.setter
    def is_running(self, value: bool):
        self._is_running.set(value)
        # Broadcast running state change
        self.master.event_generate('<<SimulationStateChange>>')

    def reset_history(self):
        """NEW ENHANCEMENT: Clears the threat history and resets the threat level visually."""
        # Fill the deque with zeros to instantly reset the sparkline visualization
        self.threat_history.clear()
        self.threat_history.extend([0] * MAX_THREAT_HISTORY)
        self.threat_level = 0  # This setter will trigger the UI update event


# --- Utility: Simple cross-platform Sound Manager (Unchanged) ---
class SoundManager:
    """Plays short audio cues. Uses platform utilities as fallback."""

    def __init__(self):
        self.os = platform.system()
        self.afplay = shutil.which('afplay')
        self.paplay = shutil.which('paplay') or shutil.which('aplay')
        self.powershell = shutil.which('powershell') or shutil.which('pwsh')
        try:
            import winsound
            self.winsound = winsound
        except Exception:
            self.winsound = None

    def play_tone(self, tone_type: str):
        """tone_type in {start, warning, critical, abort, complete}"""
        try:
            if self.os == 'Windows' and self.winsound:
                if tone_type == 'start':
                    self.winsound.Beep(800, 120);
                    self.winsound.Beep(1200, 80)
                elif tone_type == 'warning':
                    self.winsound.Beep(900, 160)
                elif tone_type == 'critical':
                    self.winsound.Beep(1500, 300);
                    self.winsound.Beep(1200, 200)
                elif tone_type == 'abort':
                    self.winsound.Beep(400, 200)
                elif tone_type == 'complete':
                    self.winsound.Beep(1000, 120)
            else:
                if self.afplay:
                    sound = '/System/Library/Sounds/Glass.aiff' if tone_type != 'critical' else '/System/Library/Sounds/Basso.aiff'
                    subprocess.Popen([self.afplay, sound], stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
                elif self.paplay:
                    subprocess.Popen([self.paplay, '/usr/share/sounds/freedesktop/stereo/complete.oga'],
                                     stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
                elif self.powershell:
                    cmd = f"[console]::beep(800,120)"
                    subprocess.Popen([self.powershell, '-Command', cmd], stdout=subprocess.DEVNULL,
                                     stderr=subprocess.DEVNULL)
                else:
                    print(f"[AUDIO - {tone_type.upper()}] (no system player found)")
        except Exception as e:
            # Silence most audio errors as they are non-critical to the application logic
            pass


# --- Optimized Animated Background (Unchanged) ---
class AnimatedBackground(tk.Canvas):
    """Optimized animated grid background with particle physics."""

    def __init__(self, parent, particle_count=DEFAULT_PARTICLE_COUNT, fps=30, **kwargs):
        super().__init__(parent, **kwargs)
        self.particles = []
        self.particle_items = []
        self.connection_items = []
        self.grid_items = []
        self.animation_running = True
        self.particle_count = particle_count
        self.fps = fps
        self.frame_delay = int(1000 / self.fps)

        width = 1200
        height = 800
        # Initialize particles and pre-create canvas items (optimization)
        for _ in range(self.particle_count):
            p = {
                'x': random.uniform(0, width),
                'y': random.uniform(0, height),
                'vx': random.uniform(-0.5, 0.5),
                'vy': random.uniform(-0.5, 0.5),
                'size': random.randint(1, 3)
            }
            self.particles.append(p)
            outer = self.create_oval(0, 0, 0, 0, outline=COLOR_NEON_BLUE, width=1, tags='particle')
            core = self.create_oval(0, 0, 0, 0, fill=COLOR_NEON_BLUE, outline='', tags='particle')
            self.particle_items.append((outer, core))

        self.bind('<Configure>', self.on_resize)
        self.draw_grid()
        self._animate_id = None
        self.animate()

    def on_resize(self, event=None):
        self.draw_grid()

    def draw_grid(self):
        # reuse grid items by clearing and redrawing only when size changes
        for gid in self.grid_items:
            try:
                self.delete(gid)
            except Exception:
                pass
        self.grid_items.clear()

        width = self.winfo_width() or 1200
        height = self.winfo_height() or 800
        step = 60
        for x in range(0, width, step):
            color = random.choice(['#0a0a1a', '#151525', '#1a1a2e'])
            gid = self.create_line(x, 0, x, height, fill=color, width=1, tags='grid')
            self.grid_items.append(gid)
        for y in range(0, height, step):
            color = random.choice(['#0a0a1a', '#151525', '#1a1a2e'])
            gid = self.create_line(0, y, width, y, fill=color, width=1, tags='grid')
            self.grid_items.append(gid)

    def animate(self):
        if not self.animation_running:
            return

        width = self.winfo_width() or 1200
        height = self.winfo_height() or 800

        # Update particle positions and reuse canvas items
        for idx, p in enumerate(self.particles):
            p['x'] += p['vx']
            p['y'] += p['vy']
            if p['x'] <= 0 or p['x'] >= width:
                p['vx'] *= -1
            if p['y'] <= 0 or p['y'] >= height:
                p['vy'] *= -1

            outer_id, core_id = self.particle_items[idx]
            x, y, s = p['x'], p['y'], p['size']
            self.coords(outer_id, x - s * 2, y - s * 2, x + s * 2, y + s * 2)
            self.coords(core_id, x - s, y - s, x + s, y + s)

        # Remove old connection lines then draw new ones selectively
        for cid in self.connection_items:
            try:
                self.delete(cid)
            except Exception:
                pass
        self.connection_items.clear()

        # Draw connections but cap number for perf
        max_conns = int(self.particle_count * 1.8)
        conns = 0
        for i, p1 in enumerate(self.particles):
            for p2 in self.particles[i + 1:]:
                if conns >= max_conns:
                    break
                dx = p1['x'] - p2['x']
                dy = p1['y'] - p2['y']
                dist = math.hypot(dx, dy)
                if dist < 100:
                    opacity = int(255 * (1 - dist / 100))
                    g = int(opacity * 0.7)
                    opacity = max(0, min(255, opacity))
                    g = max(0, min(255, g))
                    # Blueish hue
                    color = f'#{opacity:02x}{g:02x}ff'
                    cid = self.create_line(p1['x'], p1['y'], p2['x'], p2['y'], fill=color, width=1,
                                           tags='particle_conn')
                    self.connection_items.append(cid)
                    conns += 1
            if conns >= max_conns:
                break

        self._animate_id = self.after(self.frame_delay, self.animate)

    # ENHANCEMENT: Explicit cleanup
    def stop(self):
        self.animation_running = False
        if self._animate_id:
            try:
                self.after_cancel(self._animate_id)
            except Exception:
                pass
        self.delete('all')


# --- UPDATED Pseudo 3D Hologram Globe (Canvas-based) ---
class HologramGlobe(tk.Canvas):
    def __init__(self, parent, state: AppState, radius=110, points=260, fps=35, **kwargs):
        super().__init__(parent, bg=COLOR_BG_PANEL, highlightthickness=0, **kwargs)
        self.state = state  # ENHANCEMENT: Reference to AppState
        self.base_radius = radius
        self.points = []
        self.point_items = []
        self.connection_items = []
        self.max_connections = 100
        self.rotation = 0.0
        self.fps = fps
        self.frame_delay = int(1000 / self.fps)
        self.center = (self.winfo_reqwidth() // 2 or 200, self.winfo_reqheight() // 2 or 200)
        self.glitch_phase = 0

        # create sphere points using golden section spiral for even distribution
        for i in range(points):
            theta = math.acos(1 - 2 * (i + 0.5) / points)
            phi = math.pi * (1 + 5 ** 0.5) * i
            x = math.sin(theta) * math.cos(phi)
            y = math.sin(theta) * math.sin(phi)
            z = math.cos(theta)
            self.points.append([x, y, z])
            item = self.create_oval(0, 0, 0, 0, fill=COLOR_NEON_BLUE, outline='')
            self.point_items.append(item)

        self.bind('<Configure>', lambda e: self.on_resize())
        self._anim = None
        self.animate()
        # ENHANCEMENT: Bind to global state change event
        self.master.bind('<<ThreatLevelUpdate>>', self.on_level_update)

    def on_resize(self):
        w = self.winfo_width() or 300
        h = self.winfo_height() or 300
        self.center = (w / 2, h / 2)

    # ENHANCEMENT: Status update is now handled by reacting to the global event
    def on_level_update(self, event=None):
        pass  # No visual change needed immediately, animation loop handles the draw

    def project(self, x, y, z, tilt=0.6, current_radius=None):
        """Simple perspective projection, now using dynamic radius."""
        r = current_radius if current_radius is not None else self.base_radius
        factor = 1 / (1 + (z * 0.5))
        sx = x * r * factor
        sy = y * r * factor * tilt
        return sx, sy, factor

    def draw_connections(self, cx, cy, ratio, glitch_intensity):
        """Draws dynamic, glowing connections between points with smooth color transition."""

        for cid in self.connection_items:
            try:
                self.delete(cid)
            except Exception:
                pass
        self.connection_items.clear()

        if ratio < 0.05:
            return

        # --- Dynamic Connection Base Color (Smooth Lerp) ---
        if ratio < 0.7:
            conn_base_color = lerp_color(COLOR_NEON_BLUE, COLOR_NEON_ORANGE, ratio / 0.7)
        else:
            transition_ratio = (ratio - 0.7) / 0.3 if ratio < 1.0 else 1.0
            conn_base_color = lerp_color(COLOR_NEON_ORANGE, COLOR_NEON_PURPLE, transition_ratio)

        subset_points = random.sample(self.points, min(len(self.points), 80))

        connections_drawn = 0
        max_draw = self.max_connections * (ratio * 0.8 + 0.2)

        for i, p1 in enumerate(subset_points):
            x1, y1, z1 = p1
            x_rot_1 = x1 * math.cos(self.rotation) + z1 * math.sin(self.rotation)
            z_rot_1 = -x1 * math.sin(self.rotation) + z1 * math.cos(self.rotation)
            y_rot_1 = y1
            sx1, sy1, f1 = self.project(x_rot_1, y_rot_1, z_rot_1, current_radius=self.base_radius)
            screen_x1, screen_y1 = cx + sx1, cy + sy1

            for p2 in subset_points[i + 1:]:
                if connections_drawn >= max_draw:
                    return

                x2, y2, z2 = p2
                x_rot_2 = x2 * math.cos(self.rotation) + z2 * math.sin(self.rotation)
                z_rot_2 = -x2 * math.sin(self.rotation) + z2 * math.cos(self.rotation)
                y_rot_2 = y2
                sx2, sy2, f2 = self.project(x_rot_2, y_rot_2, z_rot_2, current_radius=self.base_radius)
                screen_x2, screen_y2 = cx + sx2, cy + sy2

                dx = screen_x1 - screen_x2
                dy = screen_y1 - screen_y2
                dist = math.hypot(dx, dy)

                max_dist = 60 - (glitch_intensity * 30)
                if dist < max_dist:
                    opacity = 1 - (dist / max_dist)
                    pulse_factor = 0.5 + 0.5 * math.sin(self.glitch_phase * 0.1) * ratio
                    final_opacity = max(0.1, min(1.0, opacity * pulse_factor))

                    r, g, b = hex_to_rgb(conn_base_color)
                    brightness_boost = 1.3
                    r_final = r * final_opacity * brightness_boost
                    g_final = g * final_opacity * brightness_boost
                    b_final = b * final_opacity * brightness_boost

                    color_hex = rgb_to_hex(r_final, g_final, b_final)

                    cid = self.create_line(screen_x1, screen_y1, screen_x2, screen_y2,
                                           fill=color_hex, width=1, tags='globe_conn')
                    self.connection_items.append(cid)
                    connections_drawn += 1

    def animate(self):
        level = self.state.threat_level
        active = self.state.is_running or level > 0

        ratio = level / 100.0
        rotation_boost = 1.0 + (ratio / 1.5)
        self.rotation += 0.02 * rotation_boost

        cos_r = math.cos(self.rotation)
        sin_r = math.sin(self.rotation)
        cx, cy = self.center

        glitch_intensity = ratio if level > 30 else 0

        # --- Draw dynamic connections (Aura) ---
        self.draw_connections(cx, cy, ratio, glitch_intensity)

        for idx, (x0, y0, z0) in enumerate(self.points):
            # 1. Rotation and Data Spike/Glow Effect
            x = x0 * cos_r + z0 * sin_r
            z = -x0 * sin_r + z0 * cos_r
            y = y0

            current_radius = self.base_radius
            if active and random.random() < (0.01 + glitch_intensity * 0.08):
                current_radius = self.base_radius * (1.0 + random.uniform(0.1, 0.4) * glitch_intensity)

            # 2. Projection & Sizing
            sx, sy, f = self.project(x, y, z, current_radius=current_radius)

            # Introduce visual glitch displacement on critical levels
            if level >= THREAT_COLOR_MAP['HIGH']['level'] and random.random() < 0.2:
                sx += random.randint(-4, 4)
                sy += random.randint(-4, 4)

            screen_x = cx + sx
            screen_y = cy + sy
            size = max(1, int(3 * f * (1 + glitch_intensity * 0.5)))

            # 3. Coloring: Smooth transition based on threat level and depth (f)
            if ratio < 0.7:
                point_base_color = lerp_color(COLOR_NEON_BLUE, COLOR_NEON_ORANGE, ratio / 0.7)
            else:
                transition_ratio = (ratio - 0.7) / 0.3 if ratio < 1.0 else 1.0
                point_base_color = lerp_color(COLOR_NEON_ORANGE, COLOR_NEON_PURPLE, transition_ratio)

            r_base, g_base, b_base = hex_to_rgb(point_base_color)

            # Depth: make closer points brighter (f is the depth factor)
            brightness_mod = 0.5 + 0.5 * f

            # Pulse: Critical pulse only at high level
            pulse_mod = 1.0
            if level >= THREAT_COLOR_MAP['HIGH']['level']:
                pulse_mod = 0.8 + 0.3 * math.sin(self.glitch_phase * 0.5 + idx)

            r_final = r_base * brightness_mod * pulse_mod
            g_final = g_base * brightness_mod * pulse_mod
            b_final = b_base * brightness_mod * pulse_mod

            point_col = rgb_to_hex(r_final, g_final, b_final)

            # Update coordinates and color
            self.coords(self.point_items[idx], screen_x - size, screen_y - size, screen_x + size, screen_y + size)
            try:
                self.itemconfig(self.point_items[idx], fill=point_col)
            except Exception:
                pass

        self.glitch_phase += 1
        self._anim = self.after(self.frame_delay, self.animate)

    # ENHANCEMENT: Explicit cleanup
    def stop(self):
        if self._anim:
            try:
                self.after_cancel(self._anim)
            except Exception:
                pass
        self.delete('all')


# --- GlowButton (Unchanged) ---
class GlowButton(tk.Canvas):
    def __init__(self, parent, text, command,
                 hover_bg_color=COLOR_NEON_BLUE,
                 text_color=COLOR_NEON_BLUE,
                 border_color=COLOR_NEON_BLUE,
                 hover_text_color=COLOR_BG_DARK,
                 height=44,
                 **kwargs):
        super().__init__(parent, height=height, highlightthickness=0, **kwargs)
        self.text = text
        self.command = command
        self.hover = False
        self.enabled = True
        self.glow_intensity = 0
        self._hover_bg_color = hover_bg_color
        self._text_color = text_color
        self._border_color = border_color
        self._hover_text_color = hover_text_color

        self.bind('<Button-1>', self.on_click)
        self.bind('<Enter>', self.on_enter)
        self.bind('<Leave>', self.on_leave)
        self.bind('<Configure>', lambda e: self.draw())

        self.draw()
        self.animate_glow()

    def draw(self):
        self.delete('all')
        width = self.winfo_width() or 200
        height = self.winfo_height() or 44

        if self.enabled:
            bg_color = COLOR_BG_PANEL if not self.hover else self._hover_bg_color
            text_color = self._text_color if not self.hover else self._hover_text_color
            border_color_final = self._border_color
        else:
            bg_color = '#0a0a0a'
            text_color = '#555555'
            border_color_final = '#333333'

        self.create_rectangle(2, 2, width - 2, height - 2, fill=bg_color, outline=border_color_final, width=2)

        # scanline effect
        if self.enabled:
            y_pos = (self.glow_intensity % (height - 6)) + 4
            scanline_color = self._border_color
            self.create_line(6, y_pos, width - 6, y_pos, fill=scanline_color, width=1)

        self.create_text(width / 2, height / 2, text=self.text, fill=text_color, font=('Consolas', 11, 'bold'))

    def animate_glow(self):
        self.glow_intensity = (self.glow_intensity + 2) % 100
        self.draw()
        self.after(30, self.animate_glow)

    def on_click(self, event):
        if self.enabled and self.command:
            try:
                self.command()
            except Exception as e:
                print(f"Button command failed: {e}")

    def on_enter(self, event):
        if self.enabled:
            self.hover = True
            self.draw()

    def on_leave(self, event):
        self.hover = False
        self.draw()

    def set_state(self, enabled):
        self.enabled = enabled
        self.draw()


# --- ENHANCEMENT: Traceroute Visualization Widget (Dynamic Feedback) ---
class TracerouteVisualizer(tk.Canvas):
    def __init__(self, parent, state: AppState, hops=7, fps=25, **kwargs):
        super().__init__(parent, bg=COLOR_BG_PANEL, highlightthickness=0, **kwargs)
        self.state = state  # ENHANCEMENT: Reference to AppState
        self.hops = hops
        self.fps = fps
        self.frame_delay = int(1000 / self.fps)
        self.nodes = []
        self.packets = []
        self._anim = None
        self.bind('<Configure>', lambda e: self.setup_nodes())
        self.setup_nodes()
        self.animate()

    def setup_nodes(self, event=None):
        self.delete('all')
        self.nodes.clear()
        self.packets.clear()
        width = self.winfo_width() or 300
        height = self.winfo_height() or 100

        x_positions = [width * (i / (self.hops - 1)) for i in range(self.hops)]

        # Draw base line
        self.create_line(x_positions[0], height / 2, x_positions[-1], height / 2,
                         fill="#333355", width=2, tags='traceroute_base')

        for i, x in enumerate(x_positions):
            y = height / 2
            # Initial node data (stores canvas IDs for update)
            node_id = self.create_oval(0, 0, 0, 0)
            label = "SRC" if i == 0 else "DST" if i == self.hops - 1 else f"H{i}"
            label_id = self.create_text(x, y + 15, text=label, fill=COLOR_TEXT_LIGHT, font=('Consolas', 8),
                                        tags='label')
            self.nodes.append({'x': x, 'y': y, 'label': label_id, 'node': node_id})

        self.update_nodes_visuals()

    def update_nodes_visuals(self):
        """ENHANCEMENT: Updates node colors based on current threat level."""
        level = self.state.threat_level
        is_running = self.state.is_running

        if level < THREAT_COLOR_MAP['MEDIUM']['level'] or not is_running:
            node_color = COLOR_NEON_GREEN
            active_node_color = COLOR_NEON_BLUE
        elif level < THREAT_COLOR_MAP['HIGH']['level']:
            node_color = COLOR_NEON_ORANGE
            active_node_color = COLOR_NEON_ORANGE
        else:
            node_color = COLOR_NEON_PURPLE
            active_node_color = COLOR_NEON_PURPLE

        for i, node in enumerate(self.nodes):
            x, y = node['x'], node['y']

            # Source/Destination nodes are always blue/green or static for clarity
            if i == 0 or i == self.hops - 1:
                col = COLOR_NEON_BLUE
            else:
                # Intermediate nodes show vulnerability during attack
                col = node_color if is_running else COLOR_NEON_GREEN

            # Flickering effect for compromised nodes
            if is_running and level >= THREAT_COLOR_MAP['HIGH']['level'] and i > 0 and random.random() < 0.2:
                col = COLOR_BG_PANEL if random.random() < 0.5 else active_node_color

            # Update node appearance
            self.coords(node['node'], x - 5, y - 5, x + 5, y + 5)
            self.itemconfig(node['node'], fill=col, outline=col, width=1)

    def animate(self):
        # 1. Update packets
        active_packets = []
        for p in self.packets:
            p['x'] += p['vx']

            if p['target_idx'] < len(self.nodes) and p['x'] >= self.nodes[p['target_idx']]['x']:
                p['current_idx'] = p['target_idx']
                p['target_idx'] += 1

                if p['current_idx'] == len(self.nodes) - 1:
                    continue

                next_node_x = self.nodes[p['target_idx']]['x']
                distance = next_node_x - self.nodes[p['current_idx']]['x']
                p['vx'] = distance / 10
                p['x'] = self.nodes[p['current_idx']]['x']

            active_packets.append(p)

        self.packets = active_packets

        # 2. Add new packets randomly (simulating continuous data flow)
        if random.random() < 0.08:
            start_node = self.nodes[0]
            next_node = self.nodes[1]
            distance = next_node['x'] - start_node['x']
            self.packets.append({
                'x': start_node['x'],
                'y': start_node['y'],
                'vx': distance / 10,
                'current_idx': 0,
                'target_idx': 1,
                'item_id': None
            })

        # 3. Redraw packets and update node visuals
        self.delete('packet')
        for p in self.packets:
            color = get_threat_color(self.state.threat_level) if self.state.is_running else COLOR_NEON_BLUE
            self.create_rectangle(p['x'] - 3, p['y'] - 3, p['x'] + 3, p['y'] + 3,
                                  fill=color, outline=color, width=1, tags='packet')

        self.update_nodes_visuals()

        self._anim = self.after(self.frame_delay, self.animate)

    # ENHANCEMENT: Explicit cleanup
    def stop(self):
        if self._anim:
            try:
                self.after_cancel(self._anim)
            except Exception:
                pass
        self.delete('all')


# --- System Status Panel Class (Unchanged) ---
class SystemStatusPanel(tk.Frame):
    def __init__(self, parent, state: AppState, fps=40, **kwargs):
        super().__init__(parent, bg=COLOR_BG_PANEL, highlightthickness=0, **kwargs)
        self.state = state  # ENHANCEMENT: Reference to AppState
        self.fps = fps
        self.frame_delay = int(1000 / self.fps)
        self.metrics = {
            'CPU_LOAD': 45.0,
            'MEM_UTIL': 65.0,
            'NET_IN': 5.0,
            'NET_OUT': 8.0
        }

        gauge_container = tk.Frame(self, bg=COLOR_BG_PANEL)
        gauge_container.pack(side='left', fill='y', expand=False, padx=10, pady=10)

        self.gauge_canvas = tk.Canvas(gauge_container, bg=COLOR_BG_PANEL, highlightthickness=0)
        self.gauge_canvas.pack(fill='both', expand=True)

        trace_frame = tk.Frame(self, bg=COLOR_BG_PANEL)
        trace_frame.pack(side='right', fill='both', expand=True, padx=(0, 10), pady=10)

        tk.Label(trace_frame, text="⟫ NETWORK TRACEROUTE", anchor='nw', bg=COLOR_BG_PANEL,
                 fg=COLOR_NEON_BLUE, font=('Consolas', 9)).pack(fill='x')

        # Pass state to Traceroute Visualizer
        self.traceroute = TracerouteVisualizer(trace_frame, state=self.state, height=50)
        self.traceroute.pack(fill='x', expand=True, pady=5)

        self._anim = None
        self.animate()

    def draw_gauge(self, key, value, y_start, width, height):
        canvas = self.gauge_canvas
        canvas.delete(f"{key}_gauge")
        canvas.delete(f"{key}_title")
        canvas.delete(f"{key}_value")

        gauge_height = 8
        bar_x1 = 5
        bar_x2 = width - 5
        bar_y1 = y_start + 18
        bar_y2 = bar_y1 + gauge_height

        if key in ['CPU_LOAD', 'MEM_UTIL']:
            fill_width = (value / 100) * (bar_x2 - bar_x1)
        else:
            fill_width = (value / 20) * (bar_x2 - bar_x1)

        color = COLOR_NEON_BLUE
        if key in ['CPU_LOAD', 'MEM_UTIL']:
            if value > 70:
                color = COLOR_NEON_PURPLE
            elif value > 40:
                color = COLOR_NEON_ORANGE
        else:
            color = COLOR_NEON_GREEN if key == 'NET_IN' else COLOR_NEON_BLUE

        # 1. Draw background shell
        canvas.create_rectangle(bar_x1, bar_y1, bar_x2, bar_y2, fill='#0a0a1a', outline='', tags=f"{key}_gauge")

        # 2. Draw fill
        canvas.create_rectangle(bar_x1, bar_y1, bar_x1 + fill_width, bar_y2, fill=color, outline='',
                                tags=f"{key}_gauge")

        # 3. Metric Title (Static text)
        title_text = f"⟫ {key.replace('_', ' ')}:"
        canvas.create_text(bar_x1, y_start + 5, text=title_text, anchor='nw', fill=COLOR_NEON_BLUE,
                           font=('Consolas', 9), tags=f"{key}_title")

        # 4. Metric Value (Dynamic text)
        if key in ['CPU_LOAD', 'MEM_UTIL']:
            value_text = f"{value:.1f}%"
        else:
            value_text = f"{value:.1f} MB/s"

        canvas.create_text(bar_x2, y_start + 5, text=value_text, anchor='ne', fill=COLOR_NEON_GREEN,
                           font=('Consolas', 9, 'bold'), tags=f"{key}_value")

    def animate(self):
        width = self.gauge_canvas.winfo_width() or 200
        height = self.gauge_canvas.winfo_height() or 200

        band_height = (height / 4)
        offset_y = 5

        # Simulate new data with simulation effects
        threat_mod = 1 + (self.state.threat_level / 200)

        # CPU load spikes during high threat
        cpu_sim = self.metrics['CPU_LOAD'] + random.uniform(-1.5, 1.5) * threat_mod
        self.metrics['CPU_LOAD'] = max(10, min(100, cpu_sim))

        # Memory utilization increases slightly
        mem_sim = self.metrics['MEM_UTIL'] + random.uniform(-0.8, 0.8) * (1 + threat_mod / 2)
        self.metrics['MEM_UTIL'] = max(20, min(85, mem_sim))

        # Network traffic
        self.metrics['NET_IN'] = max(0.1, min(15.0, self.metrics['NET_IN'] + random.uniform(-0.5, 0.5)))
        self.metrics['NET_OUT'] = max(0.1, min(15.0, self.metrics['NET_OUT'] + random.uniform(-0.5, 0.5)))

        self.draw_gauge('CPU_LOAD', self.metrics['CPU_LOAD'], offset_y + band_height * 0, width, height)
        self.draw_gauge('MEM_UTIL', self.metrics['MEM_UTIL'], offset_y + band_height * 1, width, height)
        self.draw_gauge('NET_IN', self.metrics['NET_IN'], offset_y + band_height * 2, width, height)
        self.draw_gauge('NET_OUT', self.metrics['NET_OUT'], offset_y + band_height * 3, width, height)

        self._anim = self.after(self.frame_delay, self.animate)

    def stop(self):
        self.traceroute.stop()
        if self._anim:
            try:
                self.after_cancel(self._anim)
            except Exception:
                pass


# --- Main Application (Updated to use AppState) ---
class CyberpunkThreatMatrix(tk.Tk):
    def __init__(self):
        super().__init__()
        self.title("CYBERPUNK THREAT MATRIX // SIMULATOR")
        self.geometry("1200x800")
        self.configure(bg=COLOR_BG_DARK)

        # ENHANCEMENT: Initialize central state manager
        self.state = AppState(self)
        self.msg_queue = queue.Queue()
        self.after(100, self.process_queue)

        self.stop_simulation_flag = False
        self.attack_buttons = {}
        self.sound = SoundManager()

        # FIX: Initialize self.abort_btn to prevent Attribute Error before it's created.
        self.abort_btn = None

        self.setup_style()
        self.create_animated_background()
        self.create_widgets()

        # ENHANCEMENT: Initial UI update relies on AppState
        self.update_threat_meter_visuals()
        self.log_message("[INIT] ▶ System online. Neural network synchronized.", "INFO")
        self.sound.play_tone('start')

        self.start_header_animation()
        self.update_data_stream()

        self.fullscreen = False
        self.bind('<F11>', lambda e: self.toggle_fullscreen())
        self.bind('<Escape>', lambda e: self.exit_fullscreen())
        self.bind('<<ThreatLevelUpdate>>', self.on_threat_update)
        self.bind('<<SimulationStateChange>>', self.on_state_change)

    # ENHANCEMENT: Event handler for UI updates
    def on_threat_update(self, event=None):
        self.update_threat_meter_visuals()

    # ENHANCEMENT: Event handler for button state and global visual cleanup
    def on_state_change(self, event=None):
        is_running = self.state.is_running
        for btn in self.attack_buttons.values():
            btn.set_state(not is_running)

        if self.abort_btn:  # Use the initialized attribute
            self.abort_btn.set_state(is_running)

    def create_animated_background(self):
        """Create the optimized animated background layer and place it behind all other widgets."""
        self.bg_canvas = AnimatedBackground(self, bg=COLOR_BG_DARK, highlightthickness=0)
        self.bg_canvas.place(x=0, y=0, relwidth=1, relheight=1)

    def setup_style(self):
        style = ttk.Style(self)
        try:
            style.theme_use('default')
        except Exception:
            pass

        style.configure('Neon.TButton', background=COLOR_BG_PANEL, foreground=COLOR_NEON_BLUE,
                        font=('Consolas', 12, 'bold'), borderwidth=3, relief="flat", padding=10)
        style.map('Neon.TButton', background=[('active', COLOR_NEON_BLUE)], foreground=[('active', COLOR_BG_DARK)],
                  relief=[('pressed', 'groove'), ('active', 'raised')])

    def create_widgets(self):
        container = tk.Frame(self, highlightthickness=0, bg=COLOR_BG_DARK)
        container.place(relx=0.5, rely=0.5, anchor='center', relwidth=0.96, relheight=0.92)
        container.lift()

        # Header (Unchanged)
        self.header_frame = tk.Frame(container, bg=COLOR_BG_DARK, height=60)
        self.header_frame.pack(fill='x', pady=(0, 10))
        self.header_canvas = tk.Canvas(self.header_frame, bg=COLOR_BG_DARK, highlightthickness=0, height=60)
        self.header_canvas.pack(fill='both', expand=True)

        # Main area with three columns
        main_frame = tk.Frame(container, bg=COLOR_BG_DARK)
        main_frame.pack(fill='both', expand=True)
        main_frame.grid_columnconfigure(0, weight=1)
        main_frame.grid_columnconfigure(1, weight=1)
        main_frame.grid_columnconfigure(2, weight=1)
        main_frame.grid_rowconfigure(0, weight=1)

        # --- LEFT COLUMN (Logs & Status) ---
        log_col = tk.Frame(main_frame, bg=COLOR_BG_DARK)
        log_col.grid(row=0, column=0, sticky='nsew', padx=4, pady=8)
        log_col.grid_rowconfigure(0, weight=3)
        log_col.grid_rowconfigure(1, weight=1)

        log_frame = self.create_panel(log_col, "◢ LIVE THREAT LOG ◣")
        log_frame.grid(row=0, column=0, sticky='nsew', padx=6, pady=6)

        self.log_text = scrolledtext.ScrolledText(log_frame, wrap=tk.WORD, height=10, bg=COLOR_BG_PANEL,
                                                  fg=COLOR_TEXT_LIGHT, font=('Consolas', 10), relief=tk.FLAT, bd=0,
                                                  insertbackground=COLOR_NEON_BLUE)
        self.log_text.pack(fill='both', expand=True, padx=10, pady=(0, 10))
        self.log_text.config(state=tk.DISABLED)
        self.log_text.tag_config("INFO", foreground=COLOR_NEON_BLUE)
        self.log_text.tag_config("WARNING", foreground=COLOR_NEON_GREEN)
        self.log_text.tag_config("ERROR", foreground=COLOR_NEON_ORANGE)
        self.log_text.tag_config("CRITICAL", foreground=COLOR_NEON_PURPLE, font=('Consolas', 10, 'bold'))

        # --- SYSTEM STATUS PANEL ---
        status_frame = self.create_panel(log_col, "◢ CORE SYSTEM STATUS ◣")
        status_frame.grid(row=1, column=0, sticky='nsew', padx=6, pady=6)
        status_frame.grid_rowconfigure(0, weight=1)

        # Pass state to System Status Panel
        self.status_panel = SystemStatusPanel(status_frame, state=self.state, fps=40)
        self.status_panel.pack(fill='both', expand=True, padx=0, pady=0)

        # --- MIDDLE COLUMN (Attack Buttons) ---
        attack_col = tk.Frame(main_frame, bg=COLOR_BG_DARK)
        attack_col.grid(row=0, column=1, sticky='nsew', padx=4, pady=8)
        attack_col.grid_rowconfigure(0, weight=1)

        attack_frame = self.create_panel(attack_col, "◢ CYBER ATTACK SIMULATOR ◣")
        attack_frame.grid(row=0, column=0, sticky='nsew', padx=6, pady=6)
        self.create_attack_buttons(attack_frame)

        # --- RIGHT COLUMN (Globe + Meter) ---
        right_col = tk.Frame(main_frame, bg=COLOR_BG_DARK)
        right_col.grid(row=0, column=2, sticky='nsew', padx=4, pady=8)
        right_col.grid_rowconfigure(0, weight=2)
        right_col.grid_rowconfigure(1, weight=1)

        globe_panel = self.create_panel(right_col, "◢ HOLOGRAM GLOBE ◣")
        globe_panel.grid(row=0, column=0, sticky='nsew', padx=6, pady=6)
        globe_panel.grid_rowconfigure(0, weight=1)

        # Pass state to Hologram Globe
        self.globe = HologramGlobe(globe_panel, state=self.state, radius=120, points=260, fps=35)
        self.globe.pack(fill='both', expand=True, padx=10, pady=10)

        meter_panel = self.create_panel(right_col, "◢ THREAT LEVEL & RECOMMENDATIONS ◣")
        meter_panel.grid(row=1, column=0, sticky='nsew', padx=6, pady=6)
        meter_panel.grid_rowconfigure(0, weight=1)

        self.threat_meter_canvas = tk.Canvas(meter_panel, height=90, bg=COLOR_BG_PANEL, highlightthickness=2,
                                             highlightbackground=COLOR_NEON_BLUE)
        self.threat_meter_canvas.pack(fill='x', padx=10, pady=10)

        self.recom_text = tk.Label(meter_panel, text="⟫ Awaiting simulation initiation...", justify=tk.LEFT,
                                   bg=COLOR_BG_PANEL, fg=COLOR_TEXT_LIGHT, font=('Consolas', 9), wraplength=320, pady=5,
                                   anchor='nw')
        self.recom_text.pack(fill='both', expand=True, padx=10, pady=(0, 10))

    # --- Other Methods ---

    def update_data_stream(self):
        """Updates the small data stream text in the header."""
        rand_ip = ".".join(str(random.randint(0, 255)) for _ in range(4))
        rand_port = random.randint(1024, 65535)
        rand_hash_short = ''.join(random.choices('0123456789abcdef', k=12))
        rand_process = random.choice(["NET_WATCH", "K_SHELL", "AUTH_SVC", "MEM_SCAN", "I/O_MON"])

        stream_content = (
            f"PROCESS: {rand_process}...\n"
            f"TARGET: {rand_ip}:{rand_port}\n"
            f"CHECKSUM: {rand_hash_short}\n"
            f"LOAD: {random.randint(10, 99)}%"
        )

        # update only label text (don't recreate widget)
        if hasattr(self, 'data_stream_label'):
            self.data_stream_label.config(text=stream_content)
        else:
            # create a small status label inside header if missing
            self.data_stream_label = tk.Label(self.header_frame, text=stream_content, bg=COLOR_BG_DARK,
                                              fg=COLOR_NEON_GREEN, font=('Consolas', 9))
            self.data_stream_label.pack(side='right', padx=8)

        self.after(400, self.update_data_stream)

    def start_header_animation(self):
        """Initializes the header animation phase."""
        self.header_phase = 0
        self.animate_header()

    # MODIFIED: Advanced Header Glitch Animation is now the default
    def animate_header(self):
        """
        Animates the pulsing and glitching header text with the updated title.
        Glitch intensity scales with threat level, and defaults to subtle pulse at 0%.
        """
        canvas = self.header_canvas
        canvas.delete('all')

        width = canvas.winfo_width() or 1200
        title = "⚡ PROTOCOL: REDLINE ⚡"
        x_pos = width / 2
        y_center = 30

        level = self.state.threat_level
        ratio = level / 100.0

        # Glitch intensity: starts subtle even at 0 (0.1 base) and scales up quickly after 20%
        # This keeps the animation active and engaging in the normal state.
        glitch_intensity = 0.1 if ratio < 0.2 else ratio

        # 1. Digital Noise/Ghosting (Scaled by intensity)
        if random.random() < (0.05 + glitch_intensity * 0.4):
            # Glitch layer 1 (Purple)
            offset_x = random.randint(-4, 4) * glitch_intensity
            offset_y = random.randint(-4, 4) * glitch_intensity
            canvas.create_text(x_pos + offset_x, y_center + offset_y, text=title,
                               fill=COLOR_NEON_PURPLE,
                               font=('Consolas', 18, 'bold'), anchor='center')

            # Glitch layer 2 (Green)
            offset_x = random.randint(-3, 3) * glitch_intensity
            offset_y = random.randint(-3, 3) * glitch_intensity
            canvas.create_text(x_pos + offset_x, y_center + offset_y, text=title,
                               fill=COLOR_NEON_GREEN,
                               font=('Consolas', 18, 'bold'), anchor='center')

        # 2. Pulsing/Main Text Effect
        alpha = int(200 + 55 * math.sin(self.header_phase * 0.1))
        alpha = max(0, min(255, alpha))

        # If threat is 0, use the blue pulse. Otherwise, use the threat color.
        pulse_color = get_threat_color(level) if level > 0 else f'#{alpha:02x}{alpha:02x}ff'

        canvas.create_text(x_pos, y_center, text=title, fill=pulse_color,
                           font=('Consolas', 18, 'bold'), anchor='center')

        # 3. Animated Separator Line
        line_offset = int(20 * math.sin(self.header_phase * 0.05))
        canvas.create_line(50 + line_offset, 50, width - 50 - line_offset, 50,
                           fill=COLOR_NEON_BLUE, width=2)

        self.header_phase += 1
        self.after(50, self.animate_header)

    def create_panel(self, parent, title):
        frame = tk.Frame(parent, bg=COLOR_BG_PANEL, highlightthickness=0)
        title_label = tk.Label(frame, text=title, bg=COLOR_BG_PANEL, fg=COLOR_NEON_BLUE, font=('Consolas', 12, 'bold'),
                               pady=8)
        title_label.pack(fill='x')
        sep = tk.Canvas(frame, height=3, bg=COLOR_BG_PANEL, highlightthickness=0)
        sep.pack(fill='x', padx=6)

        def animate_sep(phase=[0]):
            sep.delete('all')
            width = sep.winfo_width() or 200
            offset = int(8 * math.sin(phase[0] * 0.1))
            sep.create_line(offset, 1, width - offset, 1, fill=COLOR_NEON_BLUE, width=2)
            phase[0] += 1
            sep.after(80, lambda: animate_sep(phase))

        animate_sep()
        return frame

    def create_attack_buttons(self, parent):
        button_frame = tk.Frame(parent, bg=COLOR_BG_PANEL, padx=8, pady=8)
        button_frame.pack(fill='both', expand=True)

        attack_titles = {k: {
            'label': {
                'buffer_overflow': '⟫ Buffer Overflow',
                'trapdoor_activation': '⟫ Trapdoor/Backdoor',
                'privilege_escalation': '⟫ Privilege Escalation',
                'kernel_memory_corruption': '⟫ Kernel Memory Corruption',
                'cache_poisoning': '⟫ DNS Cache Poisoning',
                'side_channel_timing': '⟫ Side-Channel Timing',
                'supply_chain_poisoning': '⟫ Supply-Chain Poisoning'
            }[k]
        } for k in ATTACK_DATA.keys()}

        row = 0
        col = 0
        for attack_key in attack_titles.keys():
            title = attack_titles[attack_key]['label']
            btn = GlowButton(button_frame, title, lambda k=attack_key: self.initiate_simulation(k), bg=COLOR_BG_PANEL)
            btn.grid(row=row, column=col, sticky='ew', padx=6, pady=6)
            button_frame.grid_columnconfigure(col, weight=1)
            self.attack_buttons[attack_key] = btn
            col += 1
            if col > 1:
                col = 0
                row += 1

        self.abort_btn = GlowButton(parent, "⚡ ABORT SIMULATION ⚡", self.abort_simulation,
                                    hover_bg_color=COLOR_NEON_ORANGE, text_color=COLOR_NEON_ORANGE,
                                    border_color=COLOR_NEON_ORANGE)
        self.abort_btn.pack(fill='x', padx=8, pady=(10, 6))
        self.abort_btn.set_state(False)

    def initiate_simulation(self, attack_type: str):
        if self.state.is_running:
            return

        self.state.is_running = True
        self.stop_simulation_flag = False
        self.state.threat_level = 0
        self.state.reset_history()  # Ensure fresh start

        self.log_text.config(state=tk.NORMAL)
        self.log_text.delete(1.0, tk.END)
        self.log_message(f"[START] ⚡ Initiating {attack_type.replace('_', ' ').upper()} simulation...", "CRITICAL")
        self.log_text.config(state=tk.DISABLED)
        self.recom_text.config(text="⟫ Simulation active. Analyzing threat vector...")
        self.sound.play_tone('start')

        threading.Thread(target=self.run_simulation, args=(attack_type,), daemon=True).start()

    def abort_simulation(self):
        if not self.state.is_running:
            return
        self.stop_simulation_flag = True
        self.log_message("User requested abort. Attempting to stop simulation...", "WARNING")
        self.sound.play_tone('abort')

        # ENHANCEMENT: State reset
        self.state.is_running = False
        # NEW ENHANCEMENT: Reset history to clear the visual line
        self.state.reset_history()

    def run_simulation(self, attack_type: str):
        attack_info = ATTACK_DATA.get(attack_type)
        if not attack_info:
            self.msg_queue.put({"type": "error", "message": "Unknown attack type."})
            return

        logs = attack_info["logs"]
        total_steps = len(logs)

        try:
            for i, (severity, log_message) in enumerate(logs):
                if self.stop_simulation_flag:
                    self.msg_queue.put({"type": "error", "message": "Simulation aborted by user."})
                    break

                step = i + 1
                current_threat_level = calculate_threat_level(step, total_steps, severity)

                if severity == "CRITICAL":
                    self.sound.play_tone('critical')

                self.msg_queue.put({
                    "type": "log",
                    "severity": severity,
                    "message": log_message,
                    "threat_level": current_threat_level
                })
                time.sleep(ATTACK_SIMULATION_INTERVAL)

            if not self.stop_simulation_flag:
                self.msg_queue.put({
                    "type": "attack_complete",
                    "verdict": attack_info["verdict"],
                    "prevention": attack_info["prevention"],
                    "threat_level": 0
                })

        except Exception as e:
            self.msg_queue.put({"type": "error", "message": f"Simulation failed: {e}"})
        finally:
            if not self.stop_simulation_flag:
                self.state.is_running = False
                self.stop_simulation_flag = False

    def process_queue(self):
        try:
            while not self.msg_queue.empty():
                data = self.msg_queue.get(block=False)
                if data["type"] == "log":
                    self.log_message(data["message"], data["severity"])
                    # ENHANCEMENT: Set state property which triggers the event
                    self.state.threat_level = data["threat_level"]
                elif data["type"] == "attack_complete":
                    # ENHANCEMENT: State reset
                    self.state.is_running = False
                    # NEW ENHANCEMENT: Reset history to clear the visual line
                    self.state.reset_history()

                    self.show_recommendations(data["verdict"], data["prevention"])
                    self.sound.play_tone('complete')
                elif data["type"] == "error":
                    self.log_message(f"[SYSTEM FAILURE] {data['message']}", "CRITICAL")
                    self.recom_text.config(text="⚠ ERROR: Simulation terminated unexpectedly or aborted.")
                    self.sound.play_tone('warning')
                    # ENHANCEMENT: State reset
                    self.state.is_running = False
                    # NEW ENHANCEMENT: Reset history to clear the visual line
                    self.state.reset_history()
        except queue.Empty:
            pass

        self.after(100, self.process_queue)

    def log_message(self, message: str, severity: str):
        timestamp = datetime.now().strftime("[%H:%M:%S.%f]")[:-3]
        icon = {"INFO": "▶", "WARNING": "⚠", "ERROR": "✖", "CRITICAL": "⚡"}.get(severity, "●")
        log_line = f"{timestamp} {icon} {message}\n"

        self.log_text.config(state=tk.NORMAL)
        self.log_text.insert(tk.END, log_line, severity)
        self.log_text.see(tk.END)
        self.log_text.config(state=tk.DISABLED)

    # ENHANCEMENT: Renamed and logic simplified as it pulls from self.state
    def update_threat_meter_visuals(self):
        level = self.state.threat_level
        canvas = self.threat_meter_canvas
        canvas.delete("all")

        width = canvas.winfo_width() or 360
        height = canvas.winfo_height() or 90
        segments = 16

        # Use centralized color map
        color = get_threat_color(level)

        fill_width = (level / 100) * (width - 24)

        glitch_offset = 0
        text_fill = COLOR_TEXT_LIGHT

        if level > 50 and random.random() < 0.15:
            glitch_offset = random.randint(-3, 3)
            if random.random() < 0.4:
                text_fill = COLOR_NEON_PURPLE

        bar_y1 = 24
        bar_y2 = height - 24

        canvas.create_rectangle(12, bar_y1, width - 12, bar_y2, fill=COLOR_METER_SHELL, outline='')

        # Outer glow effect (ENHANCED for better blending)
        for i in range(3, 0, -1):  # Draw from largest to smallest for layering
            offset = i
            base_color_rgb = hex_to_rgb(color)
            r, g, b = [c + (255 - c) * 0.1 * i for c in base_color_rgb]  # Slightly brighter outline

            # Simulated gradient/transparency by blending with background
            blend_color = lerp_color(COLOR_BG_PANEL, rgb_to_hex(r, g, b), 0.8 / i)

            canvas.create_rectangle(12 - offset + glitch_offset, bar_y1 - offset,
                                    12 + fill_width + offset + glitch_offset, bar_y2 + offset,
                                    outline=blend_color, width=1)

        # Inner segmented fill
        for i in range(segments):
            seg_width = (fill_width / segments) if segments else 0
            seg_x = 12 + (i * seg_width) + glitch_offset

            # Simple color shift for segmented glow
            seg_color = lerp_color(COLOR_BG_PANEL, color, 0.4 + 0.6 * (i / segments))

            if seg_x < 12 + fill_width:
                canvas.create_rectangle(seg_x, bar_y1, min(seg_x + seg_width, 12 + fill_width), bar_y2, fill=seg_color,
                                        outline='')

        # ENHANCEMENT: Sparkline Graph Overlay
        history = list(self.state.threat_history)
        if len(history) > 1:
            line_points = []
            max_h = bar_y2 - bar_y1
            start_x = 12

            # Scale history data to canvas coordinates
            for i, hist_level in enumerate(history):
                # Map history index to x-coordinate
                x = start_x + (i / MAX_THREAT_HISTORY) * (width - 24)
                # Map level (0-100) to y-coordinate (inverted: 100=low y, 0=high y)
                y = bar_y2 - (hist_level / 100) * max_h
                line_points.extend([x, y])

            # Draw sparkline path
            canvas.create_line(line_points, fill=COLOR_NEON_GREEN, width=1, tags='sparkline')
            # Draw gradient fill below sparkline (simulated with multiple overlapping lines)
            for i in range(int(max_h)):
                # Draw faint vertical lines to create a filled-area look
                y_fill = bar_y2 - i
                fill_color = lerp_color(COLOR_BG_PANEL, COLOR_NEON_GREEN, 0.05 - (i / max_h) * 0.03)
                canvas.create_line(line_points[::2], [y_fill] * len(line_points[::2]), fill=fill_color, width=1)

            # Draw current level marker
            current_x, current_y = line_points[-2], line_points[-1]
            canvas.create_oval(current_x - 3, current_y - 3, current_x + 3, current_y + 3, fill=color, outline=color)

        # Text label (Drawn last to be on top)
        text_label = f"◢ {level}% THREAT LEVEL ◣"
        canvas.create_text(width / 2 + glitch_offset, height / 2, text=text_label, fill=text_fill,
                           font=('Consolas', 13, 'bold'))

        if level > 70:
            for i in range(2):
                x_pos = 12 + (i * (width - 24) / 2) + glitch_offset
                canvas.create_text(x_pos, height - 8, text="⚠", fill=COLOR_NEON_PURPLE, font=('Consolas', 12))

    def show_recommendations(self, verdict: str, prevention_steps: list):
        recom_text_content = f"◢ VERDICT ◣\n{verdict}\n\n◢ PREVENTION PROTOCOLS ◣\n"
        for i, step in enumerate(prevention_steps):
            recom_text_content += f"  ⟫ [{i + 1}] {step}\n"
        self.recom_text.config(text=recom_text_content)
        self.log_message("Final verdict issued. Recommendations updated.", "INFO")

    def toggle_fullscreen(self):
        self.fullscreen = not self.fullscreen
        self.attributes("-fullscreen", self.fullscreen)

    def exit_fullscreen(self):
        if self.fullscreen:
            self.fullscreen = False
            self.attributes("-fullscreen", False)


# --- Threat calculation kept as before but unchanged ---
def calculate_threat_level(step: int, total_steps: int, severity: str) -> int:
    base_level = (step / total_steps) * 70
    if severity == "INFO":
        bonus = random.randint(0, 5)
    elif severity == "WARNING":
        bonus = random.randint(5, 15)
    elif severity == "ERROR":
        bonus = random.randint(15, 25)
    elif severity == "CRITICAL":
        bonus = random.randint(25, 30)
    else:
        bonus = 0
    return min(int(base_level + bonus), MAX_THREAT_LEVEL)


if __name__ == "__main__":
    app = CyberpunkThreatMatrix()
    app.mainloop()