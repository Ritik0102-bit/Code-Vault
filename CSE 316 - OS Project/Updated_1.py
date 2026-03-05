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
import ctypes

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
DEFAULT_PARTICLE_COUNT = 24
MAX_THREAT_HISTORY = 60

# --- Platform Specific Font Scaling ---
IS_WINDOWS = platform.system() == "Windows"
# Windows fonts render larger; reduce base size
FONT_SIZE_MAIN = 9 if IS_WINDOWS else 11
FONT_SIZE_HEADER = 16 if IS_WINDOWS else 18
FONT_SIZE_BUTTON = 10 if IS_WINDOWS else 12

THREAT_COLOR_MAP = {
    'LOW': {'level': 0, 'color': COLOR_NEON_BLUE},
    'MEDIUM': {'level': 30, 'color': COLOR_NEON_ORANGE},
    'HIGH': {'level': 70, 'color': COLOR_NEON_PURPLE},
}

# --- Helpers ---
def hex_to_rgb(hex_color):
    hex_color = hex_color.lstrip('#')
    return tuple(int(hex_color[i:i + 2], 16) for i in (0, 2, 4))

def rgb_to_hex(r, g, b):
    r, g, b = int(max(0, min(255, r))), int(max(0, min(255, g))), int(max(0, min(255, b)))
    return f'#{r:02x}{g:02x}{b:02x}'

def lerp_color(color1_hex, color2_hex, ratio):
    r1, g1, b1 = hex_to_rgb(color1_hex)
    r2, g2, b2 = hex_to_rgb(color2_hex)
    r = r1 + (r2 - r1) * ratio
    g = g1 + (g2 - g1) * ratio
    b = b1 + (b2 - b1) * ratio
    return rgb_to_hex(r, g, b)

def get_threat_color(level: int) -> str:
    if level < THREAT_COLOR_MAP['MEDIUM']['level']: return THREAT_COLOR_MAP['LOW']['color']
    elif level < THREAT_COLOR_MAP['HIGH']['level']: return THREAT_COLOR_MAP['MEDIUM']['color']
    else: return THREAT_COLOR_MAP['HIGH']['color']

# --- ATTACK DATA ---
ATTACK_DATA = {
    "buffer_overflow": {
        "verdict": "Critical buffer overflow detected and mitigated.",
        "prevention": ["Implement Bounds Checking", "Use Safe Functions", "Enable ASLR & DEP"],
        "logs": [
            ("INFO", "Initializing buffer overflow simulation..."),
            ("WARNING", "Memory allocation violation detected."),
            ("ERROR", "Stack frame overwritten."),
            ("CRITICAL", "Arbitrary code execution attempt prevented!"),
            ("INFO", "Simulation completed.")
        ]
    },
    "trapdoor_activation": {
        "verdict": "Covert trapdoor activation attempt detected.",
        "prevention": ["Supply Chain Security", "Integrity Monitoring", "Network Segmentation"],
        "logs": [
            ("INFO", "Activating trapdoor simulation..."),
            ("WARNING", "Unusual network traffic originating from subnet."),
            ("ERROR", "Suspicious API call detected."),
            ("CRITICAL", "Backdoor attempt identified and blocked!"),
            ("INFO", "Simulation completed.")
        ]
    },
    "privilege_escalation": {
        "verdict": "Privilege escalation attempt identified.",
        "prevention": ["Principle of Least Privilege", "Patch Management", "Secure Configuration"],
        "logs": [
            ("INFO", "Starting privilege escalation simulation..."),
            ("WARNING", "Unauthorized access attempt to critical files."),
            ("ERROR", "Process running with elevated privileges."),
            ("CRITICAL", "Kernel security module blocked escalation!"),
            ("INFO", "Simulation completed.")
        ]
    },
    "kernel_memory_corruption": {
        "verdict": "Kernel-level memory corruption detected.",
        "prevention": ["Kernel Hardening", "Secure Drivers", "Memory Safety Languages"],
        "logs": [
            ("INFO", "Initiating kernel memory corruption simulation..."),
            ("WARNING", "Suspicious memory write in kernel space."),
            ("ERROR", "Kernel panic avoided by protection unit."),
            ("CRITICAL", "Malicious code writing to read-only memory!"),
            ("INFO", "Simulation completed.")
        ]
    },
    "cache_poisoning": {
        "verdict": "DNS cache poisoning attack detected.",
        "prevention": ["DNSSEC Implementation", "Rate Limiting", "Randomized Source Ports"],
        "logs": [
            ("INFO", "Initiating cache poisoning simulation..."),
            ("WARNING", "Abnormal DNS queries detected."),
            ("ERROR", "Spoofed DNS records injected into cache!"),
            ("CRITICAL", "DNSSEC validation failed! Entry purged."),
            ("INFO", "Simulation completed.")
        ]
    },
    "side_channel_timing": {
        "verdict": "Side-channel timing leakage detected.",
        "prevention": ["Constant-time Algorithms", "Noise Injection", "Hardware Countermeasures"],
        "logs": [
            ("INFO", "Starting side-channel timing analysis..."),
            ("WARNING", "Abnormal timing variations observed."),
            ("ERROR", "High-resolution timer usage detected."),
            ("CRITICAL", "Potential key exfiltration channel throttled!"),
            ("INFO", "Simulation completed.")
        ]
    },
    "supply_chain_poisoning": {
        "verdict": "Supply chain compromise detected.",
        "prevention": ["Artifact Signing", "Reproducible Builds", "Dependency Auditing"],
        "logs": [
            ("INFO", "Running dependency integrity checks..."),
            ("WARNING", "Unexpected checksum mismatch."),
            ("ERROR", "Unsigned module fetched from remote!"),
            ("CRITICAL", "Malicious payload identified and quarantined!"),
            ("INFO", "Simulation completed.")
        ]
    }
}

# --- State & Sound ---
class AppState:
    def __init__(self, master):
        self.master = master
        self._threat_level = tk.IntVar(value=0)
        self._is_running = tk.BooleanVar(value=False)
        self.threat_history = deque([0] * MAX_THREAT_HISTORY, maxlen=MAX_THREAT_HISTORY)

    @property
    def threat_level(self) -> int: return self._threat_level.get()
    @threat_level.setter
    def threat_level(self, value: int):
        level = max(0, min(MAX_THREAT_LEVEL, value))
        self._threat_level.set(level)
        self.threat_history.append(level)
        self.master.event_generate('<<ThreatLevelUpdate>>')
    @property
    def is_running(self) -> bool: return self._is_running.get()
    @is_running.setter
    def is_running(self, value: bool):
        self._is_running.set(value)
        self.master.event_generate('<<SimulationStateChange>>')
    def reset_history(self):
        self.threat_history.clear(); self.threat_history.extend([0] * MAX_THREAT_HISTORY); self.threat_level = 0

class SoundManager:
    def __init__(self):
        self.os = platform.system()
        try: import winsound; self.winsound = winsound
        except: self.winsound = None
        self.afplay = shutil.which('afplay')
        self.paplay = shutil.which('paplay')
    def play_tone(self, tone_type: str):
        try:
            if self.os == 'Windows' and self.winsound:
                if tone_type == 'start': self.winsound.Beep(800, 100)
                elif tone_type == 'critical': self.winsound.Beep(1500, 300)
            elif self.afplay:
                sound = '/System/Library/Sounds/Glass.aiff'
                subprocess.Popen([self.afplay, sound], stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
        except: pass

# --- Visual Components ---
class AnimatedBackground(tk.Canvas):
    def __init__(self, parent, particle_count=DEFAULT_PARTICLE_COUNT, fps=30, **kwargs):
        super().__init__(parent, **kwargs)
        self.particles = []
        self.particle_items = []
        self.connection_items = []
        self.grid_items = []
        self.width = 1280
        self.height = 800
        for _ in range(particle_count):
            self.particles.append({'x': random.uniform(0, 1280), 'y': random.uniform(0, 800), 'vx': random.uniform(-0.5, 0.5), 'vy': random.uniform(-0.5, 0.5)})
            self.particle_items.append((self.create_oval(0,0,0,0, outline=COLOR_NEON_BLUE, tags='p'), self.create_oval(0,0,0,0, fill=COLOR_NEON_BLUE, outline='', tags='p')))
        self.bind('<Configure>', self.on_resize)
        self.draw_grid()
        self.animate()

    def on_resize(self, event):
        self.width = event.width; self.height = event.height
        self.draw_grid()

    def draw_grid(self):
        self.delete('grid')
        step = 60
        for x in range(0, self.width, step):
            self.create_line(x, 0, x, self.height, fill='#0a0a1a', tags='grid')
        for y in range(0, self.height, step):
            self.create_line(0, y, self.width, y, fill='#0a0a1a', tags='grid')

    def animate(self):
        for idx, p in enumerate(self.particles):
            p['x'] += p['vx']; p['y'] += p['vy']
            if p['x'] <= 0 or p['x'] >= self.width: p['vx'] *= -1
            if p['y'] <= 0 or p['y'] >= self.height: p['vy'] *= -1
            outer, core = self.particle_items[idx]
            self.coords(outer, p['x']-4, p['y']-4, p['x']+4, p['y']+4)
            self.coords(core, p['x']-2, p['y']-2, p['x']+2, p['y']+2)
        
        # Simple connections
        self.delete('conn')
        for i, p1 in enumerate(self.particles):
            for p2 in self.particles[i+1:]:
                if abs(p1['x'] - p2['x']) < 80 and abs(p1['y'] - p2['y']) < 80:
                    self.create_line(p1['x'], p1['y'], p2['x'], p2['y'], fill='#111133', tags='conn')
        self.after(33, self.animate)

class HologramGlobe(tk.Canvas):
    def __init__(self, parent, state, **kwargs):
        super().__init__(parent, bg=COLOR_BG_PANEL, highlightthickness=0, **kwargs)
        self.state = state
        self.points = []
        self.items = []
        self.rotation = 0
        for i in range(150):
            theta = math.acos(1 - 2 * (i + 0.5) / 150)
            phi = math.pi * (1 + 5 ** 0.5) * i
            self.points.append([math.sin(theta) * math.cos(phi), math.sin(theta) * math.sin(phi), math.cos(theta)])
            self.items.append(self.create_oval(0,0,0,0, fill=COLOR_NEON_BLUE, outline=''))
        self.animate()

    def animate(self):
        w, h = self.winfo_width(), self.winfo_height()
        cx, cy = w/2, h/2
        r = min(w, h)/2 - 20
        self.rotation += 0.02 + (self.state.threat_level / 1000.0)
        cr, sr = math.cos(self.rotation), math.sin(self.rotation)
        
        color = get_threat_color(self.state.threat_level)
        
        for i, (x, y, z) in enumerate(self.points):
            rx = x * cr + z * sr
            rz = -x * sr + z * cr
            # Project
            factor = 200 / (200 + rz)
            sx = cx + rx * r * factor
            sy = cy + y * r * factor
            size = 2 * factor
            self.coords(self.items[i], sx-size, sy-size, sx+size, sy+size)
            self.itemconfig(self.items[i], fill=color)
        self.after(30, self.animate)

class GlowButton(tk.Canvas):
    def __init__(self, parent, text, command, **kwargs):
        super().__init__(parent, height=45 if not IS_WINDOWS else 40, highlightthickness=0, **kwargs)
        self.text = text
        self.command = command
        self.enabled = True
        self.bind('<Button-1>', lambda e: self.command() if self.enabled else None)
        self.bind('<Configure>', self.draw)
        
    def draw(self, event=None):
        self.delete('all')
        w, h = self.winfo_width(), self.winfo_height()
        color = COLOR_NEON_BLUE if self.enabled else '#444'
        self.create_rectangle(2, 2, w-2, h-2, outline=color, width=2)
        self.create_text(w/2, h/2, text=self.text, fill=color, font=('Consolas', FONT_SIZE_BUTTON, 'bold'))
    
    def set_state(self, state):
        self.enabled = state
        self.draw()

class SystemStatusPanel(tk.Frame):
    def __init__(self, parent, state, **kwargs):
        super().__init__(parent, bg=COLOR_BG_PANEL, **kwargs)
        self.state = state
        self.gauges = {}
        self.metrics = {'CPU': 40, 'MEM': 60, 'NET': 10}
        
        for k in self.metrics:
            f = tk.Frame(self, bg=COLOR_BG_PANEL)
            f.pack(fill='x', pady=2)
            tk.Label(f, text=k, bg=COLOR_BG_PANEL, fg=COLOR_NEON_BLUE, font=('Consolas', FONT_SIZE_MAIN), width=5).pack(side='left')
            c = tk.Canvas(f, height=10, bg='#111', highlightthickness=0)
            c.pack(side='left', fill='x', expand=True, padx=5)
            l = tk.Label(f, text="0%", bg=COLOR_BG_PANEL, fg=COLOR_NEON_GREEN, font=('Consolas', FONT_SIZE_MAIN), width=6)
            l.pack(side='right')
            self.gauges[k] = (c, l)
        self.animate()

    def animate(self):
        threat = self.state.threat_level
        for k in self.metrics:
            base = self.metrics[k]
            noise = random.randint(-5, 5) + (threat / 2)
            val = max(0, min(100, base + noise))
            canvas, label = self.gauges[k]
            
            canvas.delete('all')
            w = canvas.winfo_width()
            color = COLOR_NEON_GREEN if val < 50 else COLOR_NEON_ORANGE if val < 80 else COLOR_NEON_PURPLE
            canvas.create_rectangle(0, 0, (val/100)*w, 10, fill=color, outline='')
            label.config(text=f"{int(val)}%")
        self.after(500, self.animate)

# --- Main App ---
class CyberpunkThreatMatrix(tk.Tk):
    def __init__(self):
        super().__init__()
        
        # 1. WINDOWS DPI AWARENESS
        if IS_WINDOWS:
            try: ctypes.windll.shcore.SetProcessDpiAwareness(1)
            except: pass

        self.title("CYBERPUNK THREAT MATRIX")
        self.configure(bg=COLOR_BG_DARK)
        
        # 2. FORCE MAXIMIZE ON WINDOWS, LARGE SIZE ON MAC
        if IS_WINDOWS:
            self.state('zoomed')
        else:
            self.geometry("1280x850")

        self.state_mgr = AppState(self)
        self.sound = SoundManager()
        self.msg_queue = queue.Queue()
        self.buttons = {}
        self.stop_flag = False

        self.setup_ui()
        self.after(100, self.process_queue)

    def setup_ui(self):
        # Background
        self.bg = AnimatedBackground(self, bg=COLOR_BG_DARK, highlightthickness=0)
        self.bg.place(x=0, y=0, relwidth=1, relheight=1)

        # 3. USE PACK INSTEAD OF PLACE FOR MAIN CONTAINER TO ALLOW EXPANSION
        main_container = tk.Frame(self, bg=COLOR_BG_DARK)
        main_container.pack(fill='both', expand=True, padx=20, pady=20)

        # Header
        header = tk.Frame(main_container, bg=COLOR_BG_DARK, height=50)
        header.pack(fill='x', pady=(0, 10))
        self.header_label = tk.Label(header, text="⚡ PROTOCOL: REDLINE ⚡", bg=COLOR_BG_DARK, fg=COLOR_NEON_BLUE, font=('Consolas', FONT_SIZE_HEADER, 'bold'))
        self.header_label.pack()

        # Columns Grid
        content = tk.Frame(main_container, bg=COLOR_BG_DARK)
        content.pack(fill='both', expand=True)
        content.grid_columnconfigure(0, weight=1)
        content.grid_columnconfigure(1, weight=1)
        content.grid_columnconfigure(2, weight=1)
        content.grid_rowconfigure(0, weight=1)

        # -- Left Col --
        left_col = tk.Frame(content, bg=COLOR_BG_DARK)
        left_col.grid(row=0, column=0, sticky='nsew', padx=5)
        
        self.create_panel_title(left_col, "LIVE LOGS").pack(fill='x')
        self.log_text = scrolledtext.ScrolledText(left_col, height=10, bg=COLOR_BG_PANEL, fg=COLOR_TEXT_LIGHT, font=('Consolas', FONT_SIZE_MAIN), relief='flat')
        self.log_text.pack(fill='both', expand=True, pady=(0, 10))
        self.log_text.tag_config("CRITICAL", foreground=COLOR_NEON_PURPLE)
        
        self.create_panel_title(left_col, "SYSTEM STATUS").pack(fill='x')
        SystemStatusPanel(left_col, self.state_mgr).pack(fill='x', pady=5)

        # -- Mid Col --
        mid_col = tk.Frame(content, bg=COLOR_BG_DARK)
        mid_col.grid(row=0, column=1, sticky='nsew', padx=5)
        self.create_panel_title(mid_col, "ATTACK VECTOR").pack(fill='x')
        
        btn_frame = tk.Frame(mid_col, bg=COLOR_BG_PANEL)
        btn_frame.pack(fill='both', expand=True, pady=5)
        
        attacks = ["buffer_overflow", "trapdoor_activation", "privilege_escalation", "kernel_memory_corruption", "cache_poisoning", "supply_chain_poisoning"]
        for i, atk in enumerate(attacks):
            name = atk.replace('_', ' ').upper()
            btn = GlowButton(btn_frame, name, lambda a=atk: self.start_sim(a), bg=COLOR_BG_PANEL)
            btn.pack(fill='x', pady=2, padx=5)
            self.buttons[atk] = btn
            
        self.abort_btn = GlowButton(mid_col, "ABORT", self.abort_sim, bg=COLOR_BG_PANEL)
        self.abort_btn.pack(fill='x', pady=10)
        self.abort_btn.set_state(False)

        # -- Right Col --
        right_col = tk.Frame(content, bg=COLOR_BG_DARK)
        right_col.grid(row=0, column=2, sticky='nsew', padx=5)
        self.create_panel_title(right_col, "GLOBAL THREAT").pack(fill='x')
        
        self.globe = HologramGlobe(right_col, self.state_mgr, height=250)
        self.globe.pack(fill='x', pady=5)
        
        self.meter_canvas = tk.Canvas(right_col, height=60, bg=COLOR_BG_PANEL, highlightthickness=0)
        self.meter_canvas.pack(fill='x', pady=10)
        
        self.rec_label = tk.Label(right_col, text="System Idle...", bg=COLOR_BG_PANEL, fg=COLOR_TEXT_LIGHT, font=('Consolas', FONT_SIZE_MAIN), justify='left', wraplength=300)
        self.rec_label.pack(fill='both', expand=True)

        self.update_meter()

    def create_panel_title(self, parent, text):
        return tk.Label(parent, text=f"◢ {text} ◣", bg=COLOR_BG_PANEL, fg=COLOR_NEON_BLUE, font=('Consolas', FONT_SIZE_MAIN, 'bold'), pady=5)

    def start_sim(self, attack_type):
        if self.state_mgr.is_running: return
        self.state_mgr.is_running = True
        self.state_mgr.reset_history()
        self.stop_flag = False
        
        for b in self.buttons.values(): b.set_state(False)
        self.abort_btn.set_state(True)
        
        self.log_text.insert(tk.END, f"\n[START] {attack_type}...\n")
        self.sound.play_tone('start')
        
        threading.Thread(target=self.run_thread, args=(attack_type,), daemon=True).start()

    def abort_sim(self):
        self.stop_flag = True
        self.log_text.insert(tk.END, "\n[ABORTED BY USER]\n")

    def run_thread(self, attack_type):
        data = ATTACK_DATA[attack_type]
        steps = len(data['logs'])
        for i, (sev, msg) in enumerate(data['logs']):
            if self.stop_flag: break
            time.sleep(0.5)
            threat = int((i/steps)*100)
            self.msg_queue.put(('log', f"[{sev}] {msg}", threat))
        
        if not self.stop_flag:
            self.msg_queue.put(('done', data['verdict'], 0))
        else:
            self.msg_queue.put(('reset', '', 0))

    def process_queue(self):
        try:
            while not self.msg_queue.empty():
                type_, msg, val = self.msg_queue.get_nowait()
                if type_ == 'log':
                    self.log_text.insert(tk.END, msg + "\n", "CRITICAL" if "CRITICAL" in msg else "INFO")
                    self.log_text.see(tk.END)
                    self.state_mgr.threat_level = val
                    self.update_meter()
                elif type_ == 'done':
                    self.rec_label.config(text=f"VERDICT:\n{msg}")
                    self.end_sim()
                elif type_ == 'reset':
                    self.end_sim()
        except: pass
        self.after(100, self.process_queue)

    def end_sim(self):
        self.state_mgr.is_running = False
        for b in self.buttons.values(): b.set_state(True)
        self.abort_btn.set_state(False)
        self.state_mgr.threat_level = 0
        self.update_meter()

    def update_meter(self):
        c = self.meter_canvas
        c.delete('all')
        w, h = c.winfo_width(), c.winfo_height()
        if w < 10: w = 300
        lvl = self.state_mgr.threat_level
        col = get_threat_color(lvl)
        
        c.create_rectangle(5, 20, w-5, h-20, outline='#333')
        c.create_rectangle(5, 20, 5 + (lvl/100)*(w-10), h-20, fill=col, outline='')
        c.create_text(w/2, h/2, text=f"THREAT: {lvl}%", fill='#fff', font=('Consolas', 12, 'bold'))

if __name__ == "__main__":
    app = CyberpunkThreatMatrix()
    app.mainloop()