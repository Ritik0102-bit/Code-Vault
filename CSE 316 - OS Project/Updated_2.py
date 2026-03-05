import tkinter as tk
from tkinter import ttk, scrolledtext
import threading
import queue
import time
import random
import math
import platform
import ctypes
from collections import deque

# --- CONFIGURATION ---
COLOR_BG_DARK = "#050510"
COLOR_BG_PANEL = "#1a1a2e"
COLOR_NEON_BLUE = "#00e5ff"
COLOR_NEON_PURPLE = "#ff00e5"
COLOR_NEON_ORANGE = "#ff9900"
COLOR_NEON_GREEN = "#00ff8c"
COLOR_TEXT_LIGHT = "#e0e0e0"

IS_WINDOWS = platform.system() == "Windows"

# --- HELPERS ---
def get_font(size, weight='normal'):
    # Adjust font size for Windows scaling
    actual_size = size - 1 if IS_WINDOWS else size
    return ('Consolas', max(8, actual_size), weight)

def hex_to_rgb(hex_color):
    hex_color = hex_color.lstrip('#')
    return tuple(int(hex_color[i:i + 2], 16) for i in (0, 2, 4))

def rgb_to_hex(r, g, b):
    r, g, b = int(max(0, min(255, r))), int(max(0, min(255, g))), int(max(0, min(255, b)))
    return f'#{r:02x}{g:02x}{b:02x}'

def lerp_color(c1, c2, t):
    r1, g1, b1 = hex_to_rgb(c1)
    r2, g2, b2 = hex_to_rgb(c2)
    r = r1 + (r2 - r1) * t
    g = g1 + (g2 - g1) * t
    b = b1 + (b2 - b1) * t
    return rgb_to_hex(r, g, b)

# --- VISUAL COMPONENTS (High Fidelity) ---

class AnimatedBackground(tk.Canvas):
    def __init__(self, parent, **kwargs):
        super().__init__(parent, bg=COLOR_BG_DARK, highlightthickness=0, **kwargs)
        self.particles = []
        for _ in range(40):
            self.particles.append({
                'x': random.randint(0, 1280), 'y': random.randint(0, 800),
                'vx': random.uniform(-0.3, 0.3), 'vy': random.uniform(-0.3, 0.3),
                'size': random.randint(1, 3)
            })
        self.bind('<Configure>', self.draw_grid)
        self.animate()

    def draw_grid(self, event=None):
        self.delete('grid')
        w, h = self.winfo_width(), self.winfo_height()
        for x in range(0, w, 60):
            self.create_line(x, 0, x, h, fill='#0a0a1a', tags='grid')
        for y in range(0, h, 60):
            self.create_line(0, y, w, y, fill='#0a0a1a', tags='grid')

    def animate(self):
        w, h = self.winfo_width(), self.winfo_height()
        for p in self.particles:
            p['x'] += p['vx']; p['y'] += p['vy']
            if p['x'] < 0 or p['x'] > w: p['vx'] *= -1
            if p['y'] < 0 or p['y'] > h: p['vy'] *= -1
            
            # Draw particle
            self.delete(f"p_{id(p)}")
            x, y, s = p['x'], p['y'], p['size']
            self.create_oval(x-s, y-s, x+s, y+s, fill=COLOR_NEON_BLUE, outline='', tags=f"p_{id(p)}")
        
        # Draw connections (The "Web" effect)
        self.delete('conn')
        for i, p1 in enumerate(self.particles):
            for p2 in self.particles[i+1:]:
                dist = math.hypot(p1['x']-p2['x'], p1['y']-p2['y'])
                if dist < 100:
                    alpha = int(255 * (1 - dist/100))
                    # Simple fade simulation
                    color = '#111133' if alpha < 100 else '#222255'
                    self.create_line(p1['x'], p1['y'], p2['x'], p2['y'], fill=color, tags='conn')
                    
        self.after(50, self.animate)

class HologramGlobe(tk.Canvas):
    def __init__(self, parent, app_state, **kwargs):
        super().__init__(parent, bg=COLOR_BG_PANEL, highlightthickness=0, **kwargs)
        self.state = app_state
        self.points = []
        for i in range(250):
            theta = math.acos(1 - 2 * (i + 0.5) / 250)
            phi = math.pi * (1 + 5 ** 0.5) * i
            self.points.append([math.sin(theta) * math.cos(phi), math.sin(theta) * math.sin(phi), math.cos(theta)])
        self.rotation = 0
        self.animate()

    def animate(self):
        self.delete('all')
        w, h = self.winfo_width(), self.winfo_height()
        if w < 10: w = 300
        cx, cy = w/2, h/2
        r = min(w, h)/2 - 30
        
        # Threat level affects rotation speed and color
        lvl = self.state.threat_level
        self.rotation += 0.02 + (lvl / 800)
        cr, sr = math.cos(self.rotation), math.sin(self.rotation)
        
        # Dynamic Color
        if lvl < 30: base_col = COLOR_NEON_BLUE
        elif lvl < 70: base_col = COLOR_NEON_ORANGE
        else: base_col = COLOR_NEON_PURPLE

        # Project points
        projected = []
        for x, y, z in self.points:
            rx = x * cr + z * sr
            rz = -x * sr + z * cr
            factor = 250 / (250 + rz)
            sx, sy = cx + rx * r * factor, cy + y * r * factor
            projected.append((sx, sy, factor, rz))

        # Draw "Aura" connections for outer points
        for i in range(0, len(projected), 8): # Optimization: skip some points
             p1 = projected[i]
             if p1[3] > 0: continue # Only draw back/middle connections
             for j in range(i+1, min(i+10, len(projected))):
                 p2 = projected[j]
                 dist = math.hypot(p1[0]-p2[0], p1[1]-p2[1])
                 if dist < 40:
                     self.create_line(p1[0], p1[1], p2[0], p2[1], fill=base_col, width=1, stipple='gray50')

        # Draw dots
        for sx, sy, factor, rz in projected:
            size = 1.5 * factor
            # Glitch effect at high threat
            if lvl > 60 and random.random() < 0.05:
                sx += random.randint(-5, 5)
            self.create_oval(sx-size, sy-size, sx+size, sy+size, fill=base_col, outline='')

        self.after(40, self.animate)

class GlowButton(tk.Canvas):
    def __init__(self, parent, text, command, **kwargs):
        super().__init__(parent, height=45, bg=COLOR_BG_PANEL, highlightthickness=0, **kwargs)
        self.text = text
        self.command = command
        self.enabled = True
        self.scan_y = 0
        self.hover = False
        
        self.bind('<Button-1>', lambda e: self.command() if self.enabled else None)
        self.bind('<Enter>', self.on_enter)
        self.bind('<Leave>', self.on_leave)
        self.animate()

    def on_enter(self, e): self.hover = True
    def on_leave(self, e): self.hover = False

    def animate(self):
        self.delete('all')
        w, h = self.winfo_width(), self.winfo_height()
        
        # Colors
        if not self.enabled:
            border = '#444'
            text_col = '#666'
            bg = '#0a0a1a'
        else:
            border = COLOR_NEON_BLUE
            text_col = COLOR_NEON_BLUE
            bg = COLOR_BG_PANEL
            if self.hover:
                bg = '#111133'
                text_col = '#fff'

        # Background & Border
        self.create_rectangle(2, 2, w-2, h-2, fill=bg, outline=border, width=2)
        
        # Text
        self.create_text(w/2, h/2, text=self.text, fill=text_col, font=get_font(11, 'bold'))
        
        # Scanline Effect (The cool part)
        if self.enabled:
            self.scan_y = (self.scan_y + 2) % h
            self.create_line(2, self.scan_y, w-2, self.scan_y, fill=border, width=1, stipple='gray50')

        self.after(30, self.animate)
    
    def set_state(self, state):
        self.enabled = state

class SystemStatusPanel(tk.Frame):
    def __init__(self, parent, app_state, **kwargs):
        super().__init__(parent, bg=COLOR_BG_PANEL, **kwargs)
        self.state = app_state
        self.bars = {}
        
        metrics = ['CPU_CORE', 'MEM_ALLOC', 'NET_IO', 'DISK_R/W']
        
        for i, m in enumerate(metrics):
            # Container for one metric (Stack vertically)
            f = tk.Frame(self, bg=COLOR_BG_PANEL, pady=2)
            f.pack(fill='x', padx=10)
            
            # Header Row: Label Left, Value Right
            header = tk.Frame(f, bg=COLOR_BG_PANEL)
            header.pack(fill='x')
            tk.Label(header, text=f"⟫ {m}", fg=COLOR_NEON_BLUE, bg=COLOR_BG_PANEL, font=get_font(8)).pack(side='left')
            val_lbl = tk.Label(header, text="0%", fg=COLOR_NEON_GREEN, bg=COLOR_BG_PANEL, font=get_font(8, 'bold'))
            val_lbl.pack(side='right')
            
            # Bar Row: Below the text (Prevent overlap!)
            can = tk.Canvas(f, height=6, bg='#111', highlightthickness=0)
            can.pack(fill='x', pady=(2, 5))
            
            self.bars[m] = (can, val_lbl)
            
        self.animate()

    def animate(self):
        lvl = self.state.threat_level
        for k, (can, lbl) in self.bars.items():
            # Simulated value
            val = random.randint(10, 30) + (lvl // 1.5)
            val = min(100, val)
            
            # Update Text
            lbl.config(text=f"{int(val)}%")
            
            # Update Bar
            can.delete('all')
            w = can.winfo_width()
            col = COLOR_NEON_GREEN if val < 50 else (COLOR_NEON_ORANGE if val < 80 else COLOR_NEON_PURPLE)
            can.create_rectangle(0, 0, (val/100)*w, 6, fill=col, outline='')
            
        self.after(100, self.animate)

# --- MAIN APPLICATION ---

class CyberpunkThreatMatrix(tk.Tk):
    def __init__(self):
        super().__init__()
        
        # WINDOWS SCALING FIX
        if IS_WINDOWS:
            try: ctypes.windll.shcore.SetProcessDpiAwareness(1)
            except: pass
            self.state('zoomed') # Start maximized
        else:
            self.geometry("1300x850")

        self.title("CYBERPUNK THREAT MATRIX // REDLINE")
        self.configure(bg=COLOR_BG_DARK)
        
        # Logic State
        self.app_state = type('', (), {})() 
        self.app_state.threat_level = 0
        self.app_state.is_running = False
        self.msg_queue = queue.Queue()
        self.buttons = {}
        
        self.setup_ui()
        self.start_header_anim()
        self.after(100, self.process_queue)

    def setup_ui(self):
        # 1. Background Layer
        self.bg = AnimatedBackground(self)
        self.bg.place(x=0, y=0, relwidth=1, relheight=1)

        # 2. Main Grid Layout
        main = tk.Frame(self, bg=COLOR_BG_DARK)
        main.pack(fill='both', expand=True, padx=20, pady=20)
        
        # Header Canvas
        self.header = tk.Canvas(main, height=60, bg=COLOR_BG_DARK, highlightthickness=0)
        self.header.pack(fill='x', pady=(0, 10))

        # Content Grid (3 Columns)
        # CRITICAL FIX: minsize=300 prevents middle column collapse
        grid = tk.Frame(main, bg=COLOR_BG_DARK)
        grid.pack(fill='both', expand=True)
        grid.grid_columnconfigure(0, weight=3)
        grid.grid_columnconfigure(1, weight=2, minsize=320) # Middle column enforced width
        grid.grid_columnconfigure(2, weight=3)
        grid.grid_rowconfigure(0, weight=1)

        # --- LEFT PANEL (Logs & Status) ---
        left = tk.Frame(grid, bg=COLOR_BG_DARK)
        left.grid(row=0, column=0, sticky='nsew', padx=5)
        
        self.make_panel_header(left, "LIVE LOGS").pack(fill='x')
        self.log_box = scrolledtext.ScrolledText(left, height=15, bg=COLOR_BG_PANEL, fg=COLOR_TEXT_LIGHT, font=get_font(9), relief='flat', bd=0)
        self.log_box.pack(fill='both', expand=True, pady=(0, 10))
        self.log_box.tag_config("CRITICAL", foreground=COLOR_NEON_PURPLE)
        self.log_box.tag_config("INFO", foreground=COLOR_NEON_BLUE)
        
        self.make_panel_header(left, "SYSTEM STATUS").pack(fill='x')
        SystemStatusPanel(left, self.app_state).pack(fill='x')

        # --- MIDDLE PANEL (Buttons - Anti-Collapse) ---
        mid = tk.Frame(grid, bg=COLOR_BG_DARK)
        mid.grid(row=0, column=1, sticky='nsew', padx=10)
        
        self.make_panel_header(mid, "ATTACK VECTORS").pack(fill='x')
        
        # Button Container
        btn_box = tk.Frame(mid, bg=COLOR_BG_PANEL)
        btn_box.pack(fill='both', expand=True)
        
        attacks = [
            ("BUFFER OVERFLOW", "buffer"),
            ("TRAPDOOR ACTIVATION", "trapdoor"),
            ("PRIVILEGE ESCALATION", "privilege"),
            ("KERNEL CORRUPTION", "kernel"),
            ("CACHE POISONING", "cache"),
            ("SUPPLY CHAIN", "supply")
        ]
        
        # Spacer
        tk.Frame(btn_box, bg=COLOR_BG_PANEL, height=10).pack()
        
        for txt, key in attacks:
            btn = GlowButton(btn_box, f"⟫ {txt}", lambda k=key: self.start_simulation(k))
            btn.pack(fill='x', pady=6, padx=15)
            self.buttons[key] = btn

        self.abort_btn = GlowButton(btn_box, "⚡ ABORT SEQUENCE ⚡", self.abort_simulation)
        self.abort_btn.pack(side='bottom', fill='x', pady=20, padx=15)
        self.abort_btn.set_state(False)

        # --- RIGHT PANEL (Visuals) ---
        right = tk.Frame(grid, bg=COLOR_BG_DARK)
        right.grid(row=0, column=2, sticky='nsew', padx=5)
        
        self.make_panel_header(right, "GLOBAL THREAT MAP").pack(fill='x')
        self.globe = HologramGlobe(right, self.app_state, height=350)
        self.globe.pack(fill='both', expand=True, pady=(0, 10))
        
        self.make_panel_header(right, "THREAT LEVEL").pack(fill='x')
        self.threat_display = tk.Canvas(right, height=60, bg=COLOR_BG_PANEL, highlightthickness=0)
        self.threat_display.pack(fill='x', pady=5)
        self.update_threat_display()

    def make_panel_header(self, parent, text):
        f = tk.Frame(parent, bg=COLOR_BG_PANEL)
        tk.Label(f, text=f"◢ {text} ◣", bg=COLOR_BG_PANEL, fg=COLOR_NEON_BLUE, font=get_font(12, 'bold')).pack(pady=6)
        return f

    def start_header_anim(self):
        self.header_phase = 0
        self.anim_header()
        
    def anim_header(self):
        c = self.header
        c.delete('all')
        w = c.winfo_width() or 1000
        
        # Glitch Text
        txt = "PROTOCOL: REDLINE"
        if random.random() < 0.05:
            off = random.randint(-3, 3)
            c.create_text(w/2 + off, 30, text=txt, fill=COLOR_NEON_PURPLE, font=get_font(22, 'bold'))
        c.create_text(w/2, 30, text=txt, fill=COLOR_NEON_BLUE, font=get_font(22, 'bold'))
        
        # Scanline under text
        line_w = 400
        ph = math.sin(self.header_phase * 0.1) * 30
        c.create_line(w/2 - line_w/2 + ph, 55, w/2 + line_w/2 - ph, 55, fill=COLOR_NEON_GREEN, width=2)
        
        self.header_phase += 1
        self.after(50, self.anim_header)

    # --- SIMULATION LOGIC ---
    def start_simulation(self, key):
        if self.app_state.is_running: return
        self.app_state.is_running = True
        self.app_state.threat_level = 0
        
        for b in self.buttons.values(): b.set_state(False)
        self.abort_btn.set_state(True)
        
        self.log_box.insert(tk.END, f"\n[INIT] SEQUENCE: {key.upper()}...\n", "INFO")
        threading.Thread(target=self.run_sim, args=(key,), daemon=True).start()

    def abort_simulation(self):
        self.app_state.is_running = False
        self.log_box.insert(tk.END, "\n[ABORT] USER INTERRUPT.\n", "CRITICAL")
        self.reset_state()

    def run_sim(self, key):
        # Fake logs
        logs = [
            ("INFO", "Initializing neural handshake..."),
            ("WARNING", "Signature mismatch detected."),
            ("INFO", "Bypassing firewall layer 3..."),
            ("CRITICAL", "Intrusion detected! Escalating..."),
            ("INFO", "Deploying counter-measures..."),
            ("WARNING", "System instability imminent."),
            ("INFO", "Root access acquired."),
            ("INFO", "Simulation complete.")
        ]
        
        for sev, msg in logs:
            if not self.app_state.is_running: break
            time.sleep(0.6)
            self.msg_queue.put(('log', f"[{sev}] {msg}", sev))
            self.app_state.threat_level = min(100, self.app_state.threat_level + 15)
        
        if self.app_state.is_running:
            self.msg_queue.put(('done', None))

    def process_queue(self):
        try:
            while not self.msg_queue.empty():
                type_, msg, *args = self.msg_queue.get_nowait()
                if type_ == 'log':
                    self.log_box.insert(tk.END, msg + "\n", args[0])
                    self.log_box.see(tk.END)
                    self.update_threat_display()
                elif type_ == 'done':
                    self.reset_state()
        except: pass
        self.after(100, self.process_queue)

    def reset_state(self):
        self.app_state.is_running = False
        self.app_state.threat_level = 0
        for b in self.buttons.values(): b.set_state(True)
        self.abort_btn.set_state(False)
        self.update_threat_display()

    def update_threat_display(self):
        c = self.threat_display
        c.delete('all')
        w, h = c.winfo_width(), c.winfo_height()
        if w < 10: w=300
        lvl = self.app_state.threat_level
        col = get_threat_color(lvl)
        
        # Progress Bar Frame
        c.create_rectangle(10, 10, w-10, h-10, outline='#333', width=2)
        
        # Fill
        fill_w = (lvl/100) * (w-24)
        c.create_rectangle(12, 12, 12+fill_w, h-12, fill=col, outline='')
        
        # Text
        c.create_text(w/2, h/2, text=f"{lvl}% THREAT", fill='white', font=get_font(14, 'bold'))

def get_threat_color(lvl):
    if lvl < 30: return COLOR_NEON_BLUE
    elif lvl < 70: return COLOR_NEON_ORANGE
    return COLOR_NEON_PURPLE

if __name__ == "__main__":
    app = CyberpunkThreatMatrix()
    app.mainloop()