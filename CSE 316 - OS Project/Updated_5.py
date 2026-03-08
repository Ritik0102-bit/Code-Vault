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
from datetime import datetime

# --- SYSTEM CONFIG ---
IS_WINDOWS = platform.system() == "Windows"

# --- COLOR PALETTE (CYBER-WARFARE) ---
C_BG_DARK     = "#020205"  # Deepest Black
C_BG_PANEL    = "#0a0a12"  # Panel Background
C_ACCENT_1    = "#00f0ff"  # Cyan (Primary)
C_ACCENT_2    = "#ff003c"  # Red (Critical)
C_ACCENT_3    = "#fdf500"  # Yellow (Warning)
C_ACCENT_4    = "#00ff9f"  # Green (Stable)
C_TEXT_DIM    = "#444455"  # Inactive Text
C_GRID        = "#111118"  # Background Grid

# --- UTILS ---
def get_font(size, weight='normal', family='Consolas'):
    actual_size = size - 2 if IS_WINDOWS else size
    return (family, max(8, actual_size), weight)

# --- VISUALS ---

class CRTBackground(tk.Canvas):
    """Draws a starfield/particle web with a CRT scanline overlay."""
    def __init__(self, parent, **kwargs):
        super().__init__(parent, bg=C_BG_DARK, highlightthickness=0, **kwargs)
        self.particles = []
        for _ in range(50):
            self.particles.append({
                'x': random.randint(0, 1200), 'y': random.randint(0, 800),
                'vx': random.uniform(-0.4, 0.4), 'vy': random.uniform(-0.4, 0.4)
            })
        self.bind('<Configure>', self.draw_static)
        self.animate()

    def draw_static(self, event=None):
        self.delete('grid')
        self.delete('scanline')
        w, h = self.winfo_width(), self.winfo_height()
        
        # Cyber Grid
        for x in range(0, w, 80): self.create_line(x, 0, x, h, fill=C_GRID, tags='grid')
        for y in range(0, h, 80): self.create_line(0, y, w, y, fill=C_GRID, tags='grid')
            
        # CRT Scanlines
        for y in range(0, h, 4):
            self.create_line(0, y, w, y, fill='#050505', tags='scanline', stipple='gray25')

    def animate(self):
        w, h = self.winfo_width(), self.winfo_height()
        for p in self.particles:
            p['x'] += p['vx']; p['y'] += p['vy']
            if p['x'] < 0 or p['x'] > w: p['vx'] *= -1
            if p['y'] < 0 or p['y'] > h: p['vy'] *= -1
            
            self.delete(f"p_{id(p)}")
            self.create_rectangle(p['x'], p['y'], p['x']+2, p['y']+2, fill=C_TEXT_DIM, outline='', tags=f"p_{id(p)}")
            
        self.delete('conn')
        for i, p1 in enumerate(self.particles):
            for p2 in self.particles[i+1:]:
                if abs(p1['x']-p2['x']) < 80 and abs(p1['y']-p2['y']) < 80:
                    self.create_line(p1['x'], p1['y'], p2['x'], p2['y'], fill='#0f0f1a', tags='conn')
                    
        self.after(50, self.animate)

class HologramGlobe(tk.Canvas):
    """Clean 3D Globe (Radar removed)"""
    def __init__(self, parent, app_state, **kwargs):
        super().__init__(parent, bg=C_BG_PANEL, highlightthickness=0, **kwargs)
        self.state = app_state
        self.points = []
        # Create Sphere Points
        for i in range(200):
            theta = math.acos(1 - 2 * (i + 0.5) / 200)
            phi = math.pi * (1 + 5 ** 0.5) * i
            self.points.append([math.sin(theta) * math.cos(phi), math.sin(theta) * math.sin(phi), math.cos(theta)])
        self.rotation = 0
        self.animate()

    def animate(self):
        self.delete('all')
        w, h = self.winfo_width(), self.winfo_height()
        if w < 10: w = 300
        cx, cy = w/2, h/2
        r = min(w, h)/2 - 20
        
        lvl = self.state.threat_level
        self.rotation += 0.02 + (lvl / 800)
        cr, sr = math.cos(self.rotation), math.sin(self.rotation)
        
        col = C_ACCENT_1 if lvl < 30 else (C_ACCENT_3 if lvl < 70 else C_ACCENT_2)

        # Draw Points
        for x, y, z in self.points:
            rx = x * cr + z * sr
            rz = -x * sr + z * cr
            factor = 200 / (200 + rz)
            sx, sy = cx + rx * r * factor, cy + y * r * factor
            size = 2 * factor
            
            # Glitch effect
            if lvl > 50 and random.random() < 0.05:
                sx += random.randint(-4, 4)
                
            self.create_oval(sx-size, sy-size, sx+size, sy+size, fill=col, outline='')
            
        self.after(40, self.animate)

class HexStreamPanel(tk.Text):
    """Scrolling Matrix Hex Dump"""
    def __init__(self, parent, **kwargs):
        super().__init__(parent, bg=C_BG_PANEL, fg=C_TEXT_DIM, font=get_font(8), relief='flat', state='disabled', **kwargs)
        self.cnt = 0
        self.generate_data()

    def generate_data(self):
        line = f"0x{self.cnt:04X}  " + " ".join([f"{random.randint(0, 255):02X}" for _ in range(8)])
        self.config(state='normal')
        self.insert('end', line + "\n")
        self.see('end')
        if int(self.index('end-1c').split('.')[0]) > 20:
            self.delete('1.0', '2.0')
        self.config(state='disabled')
        self.cnt += 16
        self.after(random.randint(50, 200), self.generate_data)

class SegmentedGauge(tk.Frame):
    """Military Block Gauge"""
    def __init__(self, parent, label, color=C_ACCENT_1, **kwargs):
        super().__init__(parent, bg=C_BG_PANEL, **kwargs)
        h = tk.Frame(self, bg=C_BG_PANEL)
        h.pack(fill='x')
        tk.Label(h, text=label, fg=color, bg=C_BG_PANEL, font=get_font(8, 'bold')).pack(side='left')
        self.val_lbl = tk.Label(h, text="0%", fg=C_TEXT_DIM, bg=C_BG_PANEL, font=get_font(8))
        self.val_lbl.pack(side='right')
        
        self.canvas = tk.Canvas(self, height=8, bg=C_BG_PANEL, highlightthickness=0)
        self.canvas.pack(fill='x', pady=2)
        self.color = color
        self.value = 0.0
        self.target = 0.0
        self.animate()

    def set_value(self, val):
        self.target = val

    def animate(self):
        # Physics smoothing
        self.value += (self.target - self.value) * 0.1
        self.val_lbl.config(text=f"{int(self.value)}%")
        
        self.canvas.delete('all')
        w = self.canvas.winfo_width()
        if w > 1:
            total_segs = 20
            seg_w = w / total_segs
            active_segs = int((self.value / 100) * total_segs)
            for i in range(total_segs):
                x = i * seg_w
                fill = self.color if i < active_segs else '#1a1a25'
                self.canvas.create_rectangle(x, 0, x+seg_w-2, 8, fill=fill, outline='')
        self.after(50, self.animate)

class TechButton(tk.Canvas):
    """Button with Brackets"""
    def __init__(self, parent, text, command, **kwargs):
        super().__init__(parent, height=40, bg=C_BG_PANEL, highlightthickness=0, **kwargs)
        self.text = text
        self.command = command
        self.state = 'normal'
        self.hover = False
        self.bind('<Button-1>', self.on_click)
        self.bind('<Enter>', lambda e: self.set_hover(True))
        self.bind('<Leave>', lambda e: self.set_hover(False))
        self.bind('<Configure>', self.draw)

    def set_hover(self, val):
        self.hover = val; self.draw()

    def set_active(self, val):
        self.state = 'active' if val else 'normal'; self.draw()

    def on_click(self, e):
        if self.state != 'disabled': self.command()

    def draw(self, e=None):
        self.delete('all')
        w, h = self.winfo_width(), self.winfo_height()
        if self.state == 'disabled': fg, bg = C_TEXT_DIM, C_BG_PANEL
        elif self.state == 'active': fg, bg = C_BG_PANEL, C_ACCENT_1
        elif self.hover: fg, bg = C_ACCENT_1, '#11111f'
        else: fg, bg = C_ACCENT_1, C_BG_PANEL

        self.create_rectangle(0, 0, w, h, fill=bg, outline='')
        if self.state != 'active':
            self.create_line(10, 5, 5, 5, 5, h-5, 10, h-5, fill=fg, width=2)
            self.create_line(w-10, 5, w-5, 5, w-5, h-5, w-10, h-5, fill=fg, width=2)
        self.create_text(w/2, h/2, text=self.text, fill=fg, font=get_font(10, 'bold'))

# --- APP ---

class AdvancedThreatMatrix(tk.Tk):
    def __init__(self):
        super().__init__()
        if IS_WINDOWS:
            try: ctypes.windll.shcore.SetProcessDpiAwareness(1)
            except: pass
            self.state('zoomed')
        else:
            self.geometry("1400x900")

        self.title("CYBER-WARFARE CONSOLE // MK-IV")
        self.configure(bg=C_BG_DARK)
        
        self.app_state = type('', (), {})()
        self.app_state.is_running = False
        self.app_state.threat_level = 0
        self.msg_queue = queue.Queue()
        self.start_time = time.time()
        
        self.setup_layout()
        self.start_loops()

    def setup_layout(self):
        # 1. Background
        self.bg = CRTBackground(self)
        self.bg.place(x=0, y=0, relwidth=1, relheight=1)

        # 2. Main Padding
        main = tk.Frame(self, bg=C_BG_DARK)
        main.pack(fill='both', expand=True, padx=15, pady=15)

        # 3. Header
        self.header_cvs = tk.Canvas(main, height=50, bg=C_BG_DARK, highlightthickness=0)
        self.header_cvs.pack(fill='x', pady=(0, 10))

        # 4. Grid
        grid = tk.Frame(main, bg=C_BG_DARK)
        grid.pack(fill='both', expand=True)
        grid.grid_columnconfigure(0, weight=3, minsize=300)
        grid.grid_columnconfigure(1, weight=2, minsize=320)
        grid.grid_columnconfigure(2, weight=3, minsize=300)
        grid.grid_rowconfigure(0, weight=1)

        # --- LEFT (Intel) ---
        col1 = self.make_panel_frame(grid, 0, 0)
        self.make_header(col1, "MEMORY DUMP", C_ACCENT_4)
        HexStreamPanel(col1, height=8).pack(fill='x', padx=5, pady=5)
        
        self.make_header(col1, "EVENT LOGS", C_ACCENT_1)
        self.log_box = scrolledtext.ScrolledText(col1, height=12, bg=C_BG_PANEL, fg=C_TEXT_DIM, font=get_font(9), relief='flat', bd=0)
        self.log_box.pack(fill='both', expand=True, padx=5, pady=5)
        self.log_box.tag_config("CRITICAL", foreground=C_ACCENT_2)
        self.log_box.tag_config("WARNING", foreground=C_ACCENT_3)
        self.log_box.tag_config("INFO", foreground=C_ACCENT_1)

        self.make_header(col1, "SYSTEM INTEGRITY", C_ACCENT_3)
        self.gauges = {}
        for metric, col in [("CPU_CORE", C_ACCENT_1), ("RAM_ALLOC", C_ACCENT_4), ("NET_FLUX", C_ACCENT_3)]:
            g = SegmentedGauge(col1, metric, color=col)
            g.pack(fill='x', padx=5, pady=2)
            self.gauges[metric] = g

        # --- MID (Counter Measures) ---
        col2 = self.make_panel_frame(grid, 0, 1)
        self.make_header(col2, "COUNTER MEASURES", C_ACCENT_1)
        
        btn_frame = tk.Frame(col2, bg=C_BG_PANEL)
        btn_frame.pack(fill='both', expand=True, padx=10, pady=10)
        
        self.buttons = {}
        # RESTORED ORIGINAL ATTACK LIST
        cmds = [
            ("BUFFER OVERFLOW", "buffer_overflow"),
            ("TRAPDOOR ACTIVATION", "trapdoor_activation"),
            ("PRIVILEGE ESCALATION", "privilege_escalation"),
            ("KERNEL CORRUPTION", "kernel_memory_corruption"),
            ("CACHE POISONING", "cache_poisoning"),
            ("SUPPLY CHAIN", "supply_chain_poisoning")
        ]
        
        for txt, key in cmds:
            b = TechButton(btn_frame, txt, lambda k=key: self.start_sim(k))
            b.pack(fill='x', pady=5)
            self.buttons[key] = b

        self.abort_btn = TechButton(btn_frame, "/// ABORT SEQUENCE ///", self.abort_sim)
        self.abort_btn.pack(side='bottom', fill='x', pady=20)
        self.abort_btn.state = 'disabled'

        # --- RIGHT (Visuals) ---
        col3 = self.make_panel_frame(grid, 0, 2)
        self.make_header(col3, "GLOBAL SURVEILLANCE", C_ACCENT_2)
        
        self.globe = HologramGlobe(col3, self.app_state, height=300)
        self.globe.pack(fill='both', expand=True, padx=5, pady=5)
        
        self.make_header(col3, "THREAT INDEX", C_ACCENT_2)
        self.threat_label = tk.Label(col3, text="0%", font=get_font(30, 'bold'), fg=C_ACCENT_1, bg=C_BG_PANEL)
        self.threat_label.pack(pady=20)
        self.status_lbl = tk.Label(col3, text="SYSTEM STANDBY", font=get_font(10), fg=C_TEXT_DIM, bg=C_BG_PANEL)
        self.status_lbl.pack()

    def make_panel_frame(self, parent, r, c):
        f = tk.Frame(parent, bg=C_BG_PANEL, highlightbackground=C_GRID, highlightthickness=1)
        f.grid(row=r, column=c, sticky='nsew', padx=5)
        return f

    def make_header(self, parent, text, color):
        f = tk.Frame(parent, bg=C_BG_PANEL)
        f.pack(fill='x', pady=(10, 2), padx=5)
        tk.Frame(f, width=5, height=15, bg=color).pack(side='left', padx=(0, 5))
        tk.Label(f, text=text, fg=color, bg=C_BG_PANEL, font=get_font(10, 'bold')).pack(side='left')

    def start_loops(self):
        self.update_header()
        self.update_gauges()
        self.process_queue()

    def update_header(self):
        c = self.header_cvs
        c.delete('all')
        w = c.winfo_width()
        
        t_str = datetime.now().strftime("%H:%M:%S")
        elapsed = int(time.time() - self.start_time)
        session = f"SESSION: {elapsed:04d}s"
        target = f"STATUS: {'LOCKED' if self.app_state.is_running else 'IDLE'}"
        
        c.create_text(10, 25, text="PROTOCOL: REDLINE // MK-IV", fill=C_ACCENT_1, font=get_font(14, 'bold'), anchor='w')
        info_str = f"{target}  |  {session}  |  T-MINUS: {t_str}"
        c.create_text(w-10, 25, text=info_str, fill=C_ACCENT_4, font=get_font(10), anchor='e')
        
        c.create_line(0, 48, w, 48, fill=C_GRID, width=2)
        pos = (time.time() * 300) % w
        c.create_line(pos, 48, pos+50, 48, fill=C_ACCENT_1, width=2)
        
        self.after(50, self.update_header)

    def update_gauges(self):
        base_load = 10
        if self.app_state.is_running: base_load = 50 + (self.app_state.threat_level / 2)
        for k, g in self.gauges.items():
            noise = random.randint(-5, 10)
            g.set_value(min(100, max(0, base_load + noise)))
        self.after(200, self.update_gauges)

    def start_sim(self, key):
        if self.app_state.is_running: return
        self.app_state.is_running = True
        self.app_state.threat_level = 0
        
        for b in self.buttons.values(): b.state = 'disabled'; b.draw()
        self.buttons[key].set_active(True)
        self.abort_btn.state = 'active'; self.abort_btn.draw()
        
        self.log_box.insert('end', f"\n>> INIT SEQUENCE: {key.upper().replace('_', ' ')}\n", "INFO")
        self.status_lbl.config(text="⚠ ACTIVE THREAT", fg=C_ACCENT_2)
        
        threading.Thread(target=self.sim_worker, args=(key,), daemon=True).start()

    def abort_sim(self):
        self.app_state.is_running = False
        self.log_box.insert('end', "\n>> MANUAL ABORT TRIGGERED\n", "CRITICAL")
        self.reset_ui()

    def sim_worker(self, key):
        # Simulation Logic
        logs = [
            ("INFO", "Initializing neural handshake..."),
            ("WARNING", "Encryption keys rotating."),
            ("INFO", "Packet injection started."),
            ("CRITICAL", "Anomaly detected in sector 7."),
            ("WARNING", "Cpu thermal throttle."),
            ("INFO", "Payload delivered successfully.")
        ]
        
        for sev, msg in logs:
            if not self.app_state.is_running: break
            time.sleep(0.8)
            self.msg_queue.put(('log', f"[{sev}] {msg}", sev))
            self.app_state.threat_level = min(100, self.app_state.threat_level + 20)
        
        if self.app_state.is_running:
            self.msg_queue.put(('done', None))

    def process_queue(self):
        try:
            while not self.msg_queue.empty():
                type_, msg, *args = self.msg_queue.get_nowait()
                if type_ == 'log':
                    self.log_box.insert('end', f"{datetime.now().strftime('%H:%M:%S')} {msg}\n", args[0])
                    self.log_box.see('end')
                    t = self.app_state.threat_level
                    col = C_ACCENT_4 if t < 30 else (C_ACCENT_3 if t < 70 else C_ACCENT_2)
                    self.threat_label.config(text=f"{t}%", fg=col)
                elif type_ == 'done':
                    self.log_box.insert('end', ">> SEQUENCE COMPLETE\n", "INFO")
                    self.reset_ui()
        except: pass
        self.after(100, self.process_queue)

    def reset_ui(self):
        self.app_state.is_running = False
        self.app_state.threat_level = 0
        self.threat_label.config(text="0%", fg=C_ACCENT_1)
        self.status_lbl.config(text="SYSTEM STANDBY", fg=C_TEXT_DIM)
        for b in self.buttons.values(): b.state = 'normal'; b.draw()
        self.abort_btn.state = 'disabled'; self.abort_btn.draw()

if __name__ == "__main__":
    app = AdvancedThreatMatrix()
    app.mainloop()