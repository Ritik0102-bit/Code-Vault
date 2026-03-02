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
    # Windows renders fonts larger/bolder than Mac
    actual_size = size - 2 if IS_WINDOWS else size
    return (family, max(8, actual_size), weight)

def hex_color(r, g, b):
    return f'#{r:02x}{g:02x}{b:02x}'

# --- CUSTOM WIDGETS ---

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
        
        # 1. Cyber Grid
        for x in range(0, w, 80):
            self.create_line(x, 0, x, h, fill=C_GRID, tags='grid')
        for y in range(0, h, 80):
            self.create_line(0, y, w, y, fill=C_GRID, tags='grid')
            
        # 2. CRT Scanlines (Static overlay)
        for y in range(0, h, 4):
            self.create_line(0, y, w, y, fill='#050505', tags='scanline', stipple='gray25')

    def animate(self):
        w, h = self.winfo_width(), self.winfo_height()
        for p in self.particles:
            p['x'] += p['vx']; p['y'] += p['vy']
            if p['x'] < 0 or p['x'] > w: p['vx'] *= -1
            if p['y'] < 0 or p['y'] > h: p['vy'] *= -1
            
            self.delete(f"p_{id(p)}")
            # Draw particle
            self.create_rectangle(p['x'], p['y'], p['x']+2, p['y']+2, fill=C_TEXT_DIM, outline='', tags=f"p_{id(p)}")
            
        # Draw "Plexus" connections
        self.delete('conn')
        for i, p1 in enumerate(self.particles):
            for p2 in self.particles[i+1:]:
                if abs(p1['x']-p2['x']) < 80 and abs(p1['y']-p2['y']) < 80:
                    self.create_line(p1['x'], p1['y'], p2['x'], p2['y'], fill='#0f0f1a', tags='conn')
                    
        self.after(50, self.animate)

class RadarScope(tk.Canvas):
    """A rotating radar that reveals 'ghost' targets."""
    def __init__(self, parent, app_state, **kwargs):
        super().__init__(parent, bg=C_BG_PANEL, highlightthickness=0, **kwargs)
        self.state = app_state
        self.angle = 0
        self.targets = [] # List of (dist, angle, age)
        self.animate()

    def animate(self):
        self.delete('all')
        w, h = self.winfo_width(), self.winfo_height()
        if w < 10: w = 300
        cx, cy = w/2, h/2
        radius = min(w, h)/2 - 15
        
        # 1. Draw Radar Rings
        for r in range(1, 4):
            curr_r = radius * (r/3)
            self.create_oval(cx-curr_r, cy-curr_r, cx+curr_r, cy+curr_r, outline=C_GRID, width=1)
        
        # 2. Draw Crosshair
        self.create_line(cx-radius, cy, cx+radius, cy, fill=C_GRID)
        self.create_line(cx, cy-radius, cx, cy+radius, fill=C_GRID)

        # 3. Sweep Line
        self.angle = (self.angle + 4) % 360
        rad = math.radians(self.angle)
        ex = cx + math.cos(rad) * radius
        ey = cy + math.sin(rad) * radius
        
        # Gradient Sweep Trail
        for i in range(20):
            trail_ang = math.radians(self.angle - i)
            tx = cx + math.cos(trail_ang) * radius
            ty = cy + math.sin(trail_ang) * radius
            color = '#004444' if i > 5 else C_ACCENT_1
            self.create_line(cx, cy, tx, ty, fill=color, width=2 if i==0 else 1, stipple='gray50' if i>0 else '')

        # 4. Generate Random Targets if Active
        if self.state.is_running and random.random() < 0.05:
            # (distance_factor, angle_deg, life_counter)
            self.targets.append([random.uniform(0.2, 0.9), random.randint(0, 360), 100])

        # 5. Draw Targets
        active_targets = []
        for t in self.targets:
            dist, ang, life = t
            t_rad = math.radians(ang)
            tx = cx + math.cos(t_rad) * (radius * dist)
            ty = cy + math.sin(t_rad) * (radius * dist)
            
            # Opacity based on life
            color = C_ACCENT_2 # Hostile Red
            
            # Only draw if sweep is close or just passed
            ang_diff = (self.angle - ang) % 360
            if ang_diff < 30:
                self.create_text(tx, ty, text="✖", fill=color, font=get_font(10, 'bold'))
                self.create_text(tx+10, ty, text=f"UNK-{random.randint(10,99)}", fill=C_ACCENT_2, font=get_font(6), anchor='w')
            
            t[2] -= 2 # Decay life
            if t[2] > 0: active_targets.append(t)
            
        self.targets = active_targets
        self.after(30, self.animate)

class HexStreamPanel(tk.Text):
    """A scrolling matrix of hex code."""
    def __init__(self, parent, **kwargs):
        super().__init__(parent, bg=C_BG_PANEL, fg=C_TEXT_DIM, font=get_font(8), relief='flat', state='disabled', **kwargs)
        self.cnt = 0
        self.generate_data()

    def generate_data(self):
        # Generate a line of random hex
        line = f"0x{self.cnt:04X}  " + " ".join([f"{random.randint(0, 255):02X}" for _ in range(8)])
        
        self.config(state='normal')
        self.insert('end', line + "\n")
        self.see('end')
        
        # Limit buffer
        if int(self.index('end-1c').split('.')[0]) > 20:
            self.delete('1.0', '2.0')
            
        self.config(state='disabled')
        self.cnt += 16
        # Random interval for "bursty" data look
        self.after(random.randint(50, 200), self.generate_data)

class SegmentedGauge(tk.Frame):
    """A block-style progress bar: [|||||     ]"""
    def __init__(self, parent, label, color=C_ACCENT_1, **kwargs):
        super().__init__(parent, bg=C_BG_PANEL, **kwargs)
        
        # Header
        h = tk.Frame(self, bg=C_BG_PANEL)
        h.pack(fill='x')
        tk.Label(h, text=label, fg=color, bg=C_BG_PANEL, font=get_font(8, 'bold')).pack(side='left')
        self.val_lbl = tk.Label(h, text="0%", fg=C_TEXT_DIM, bg=C_BG_PANEL, font=get_font(8))
        self.val_lbl.pack(side='right')
        
        # Segments
        self.canvas = tk.Canvas(self, height=8, bg=C_BG_PANEL, highlightthickness=0)
        self.canvas.pack(fill='x', pady=2)
        self.color = color
        self.value = 0
        self.target = 0
        self.animate()

    def set_value(self, val):
        self.target = val

    def animate(self):
        # Smooth interpolation
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
    """Button with a bracket hover effect: [ TEXT ]"""
    def __init__(self, parent, text, command, **kwargs):
        super().__init__(parent, height=40, bg=C_BG_PANEL, highlightthickness=0, **kwargs)
        self.text = text
        self.command = command
        self.state = 'normal' # normal, active, disabled
        self.hover = False
        
        self.bind('<Button-1>', self.on_click)
        self.bind('<Enter>', lambda e: self.set_hover(True))
        self.bind('<Leave>', lambda e: self.set_hover(False))
        self.bind('<Configure>', self.draw)

    def set_hover(self, val):
        self.hover = val
        self.draw()

    def set_active(self, val):
        self.state = 'active' if val else 'normal'
        self.draw()

    def on_click(self, e):
        if self.state != 'disabled': self.command()

    def draw(self, e=None):
        self.delete('all')
        w, h = self.winfo_width(), self.winfo_height()
        
        # Colors
        if self.state == 'disabled':
            fg, bg = C_TEXT_DIM, C_BG_PANEL
        elif self.state == 'active':
            fg, bg = C_BG_PANEL, C_ACCENT_1
        elif self.hover:
            fg, bg = C_ACCENT_1, '#11111f'
        else:
            fg, bg = C_ACCENT_1, C_BG_PANEL

        # Background
        self.create_rectangle(0, 0, w, h, fill=bg, outline='')
        
        # Brackets
        if self.state != 'active':
            # Left Bracket
            self.create_line(10, 5, 5, 5, 5, h-5, 10, h-5, fill=fg, width=2)
            # Right Bracket
            self.create_line(w-10, 5, w-5, 5, w-5, h-5, w-10, h-5, fill=fg, width=2)
        
        # Text
        self.create_text(w/2, h/2, text=self.text, fill=fg, font=get_font(10, 'bold'))

# --- MAIN APPLICATION ---

class AdvancedThreatMatrix(tk.Tk):
    def __init__(self):
        super().__init__()
        # DPI Scaling for Windows
        if IS_WINDOWS:
            try: ctypes.windll.shcore.SetProcessDpiAwareness(1)
            except: pass
            self.state('zoomed')
        else:
            self.geometry("1400x900")

        self.title("CYBER-WARFARE CONSOLE // MK-IV")
        self.configure(bg=C_BG_DARK)
        
        # State
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

        # 2. Main Container (Padding)
        main = tk.Frame(self, bg=C_BG_DARK)
        main.pack(fill='both', expand=True, padx=15, pady=15)

        # 3. Header
        self.header_cvs = tk.Canvas(main, height=50, bg=C_BG_DARK, highlightthickness=0)
        self.header_cvs.pack(fill='x', pady=(0, 10))

        # 4. Three-Column Grid
        grid = tk.Frame(main, bg=C_BG_DARK)
        grid.pack(fill='both', expand=True)
        # Column weights and min-sizes to prevent collapse
        grid.grid_columnconfigure(0, weight=3, minsize=300)
        grid.grid_columnconfigure(1, weight=2, minsize=250)
        grid.grid_columnconfigure(2, weight=3, minsize=300)
        grid.grid_rowconfigure(0, weight=1)

        # --- LEFT COLUMN (Intel & Logs) ---
        col1 = self.make_panel_frame(grid, 0, 0)
        
        self.make_header(col1, "LIVE DATA STREAM", C_ACCENT_4)
        # Hex Dump
        hex_panel = HexStreamPanel(col1, height=8)
        hex_panel.pack(fill='x', padx=5, pady=5)
        
        self.make_header(col1, "EVENT LOGS", C_ACCENT_1)
        self.log_box = scrolledtext.ScrolledText(col1, height=12, bg=C_BG_PANEL, fg=C_TEXT_DIM, font=get_font(9), relief='flat', bd=0)
        self.log_box.pack(fill='both', expand=True, padx=5, pady=5)
        self.log_box.tag_config("CRITICAL", foreground=C_ACCENT_2)
        self.log_box.tag_config("WARNING", foreground=C_ACCENT_3)
        self.log_box.tag_config("INFO", foreground=C_ACCENT_1)

        self.make_header(col1, "RESOURCE USAGE", C_ACCENT_3)
        self.gauges = {}
        for metric, col in [("CPU_CORE_0", C_ACCENT_1), ("MEM_ALLOC", C_ACCENT_4), ("NET_UPLINK", C_ACCENT_3)]:
            g = SegmentedGauge(col1, metric, color=col)
            g.pack(fill='x', padx=5, pady=2)
            self.gauges[metric] = g

        # --- MIDDLE COLUMN (Command) ---
        col2 = self.make_panel_frame(grid, 0, 1)
        self.make_header(col2, "COUNTER-MEASURES", C_ACCENT_1)
        
        btn_frame = tk.Frame(col2, bg=C_BG_PANEL)
        btn_frame.pack(fill='both', expand=True, padx=10, pady=10)
        
        self.buttons = {}
        cmds = [
            ("DEPLOY FIREWALL", "firewall"),
            ("TRACE ROUTE", "trace"),
            ("PACKET SNIFFER", "sniffer"),
            ("BRUTE FORCE", "brute"),
            ("ISOLATE NODE", "isolate")
        ]
        
        for txt, key in cmds:
            b = TechButton(btn_frame, txt, lambda k=key: self.start_sim(k))
            b.pack(fill='x', pady=5)
            self.buttons[key] = b

        self.abort_btn = TechButton(btn_frame, "/// EMERGENCY ABORT ///", self.abort_sim)
        self.abort_btn.pack(side='bottom', fill='x', pady=20)
        self.abort_btn.state = 'disabled'

        # --- RIGHT COLUMN (Visuals) ---
        col3 = self.make_panel_frame(grid, 0, 2)
        self.make_header(col3, "LONG RANGE SENSORS", C_ACCENT_2)
        
        # Radar
        self.radar = RadarScope(col3, self.app_state, height=300)
        self.radar.pack(fill='both', expand=True, padx=5, pady=5)
        
        self.make_header(col3, "GLOBAL THREAT INDEX", C_ACCENT_2)
        self.threat_label = tk.Label(col3, text="0%", font=get_font(30, 'bold'), fg=C_ACCENT_1, bg=C_BG_PANEL)
        self.threat_label.pack(pady=20)
        
        # Decorative status text
        self.status_lbl = tk.Label(col3, text="SYSTEM STANDBY", font=get_font(10), fg=C_TEXT_DIM, bg=C_BG_PANEL)
        self.status_lbl.pack()

    def make_panel_frame(self, parent, r, c):
        f = tk.Frame(parent, bg=C_BG_PANEL, highlightbackground=C_GRID, highlightthickness=1)
        f.grid(row=r, column=c, sticky='nsew', padx=5)
        return f

    def make_header(self, parent, text, color):
        f = tk.Frame(parent, bg=C_BG_PANEL)
        f.pack(fill='x', pady=(10, 2), padx=5)
        # Decorative square
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
        
        # Dynamic Text
        t_str = datetime.now().strftime("%H:%M:%S")
        elapsed = int(time.time() - self.start_time)
        session = f"SESSION: {elapsed:04d}s"
        target = f"TARGET: {'LOCKED' if self.app_state.is_running else 'SCANNING...'}"
        
        # Left Info
        c.create_text(10, 25, text="PROTOCOL: REDLINE // MK-IV", fill=C_ACCENT_1, font=get_font(14, 'bold'), anchor='w')
        
        # Right Info
        info_str = f"{target}  |  {session}  |  T-MINUS: {t_str}"
        c.create_text(w-10, 25, text=info_str, fill=C_ACCENT_4, font=get_font(10), anchor='e')
        
        # Bottom Line
        c.create_line(0, 48, w, 48, fill=C_GRID, width=2)
        # Moving Blip
        pos = (time.time() * 300) % w
        c.create_line(pos, 48, pos+50, 48, fill=C_ACCENT_1, width=2)
        
        self.after(50, self.update_header)

    def update_gauges(self):
        # Fluctuate gauges based on threat level
        base_load = 10
        if self.app_state.is_running: base_load = 50 + (self.app_state.threat_level / 2)
        
        for k, g in self.gauges.items():
            noise = random.randint(-5, 10)
            g.set_value(min(100, max(0, base_load + noise)))
            
        self.after(200, self.update_gauges)

    # --- LOGIC ---
    def start_sim(self, key):
        if self.app_state.is_running: return
        self.app_state.is_running = True
        self.app_state.threat_level = 0
        
        # Update Buttons
        for b in self.buttons.values(): b.state = 'disabled'; b.draw()
        self.buttons[key].set_active(True)
        self.abort_btn.state = 'active'; self.abort_btn.draw()
        
        self.log_box.insert('end', f"\n>> INIT SEQUENCE: {key.upper()}\n", "INFO")
        self.status_lbl.config(text="⚠ INTRUSION DETECTED", fg=C_ACCENT_2)
        
        threading.Thread(target=self.sim_worker, args=(key,), daemon=True).start()

    def abort_sim(self):
        self.app_state.is_running = False
        self.log_box.insert('end', "\n>> MANUAL ABORT TRIGGERED\n", "CRITICAL")
        self.reset_ui()

    def sim_worker(self, key):
        logs = [
            ("INFO", "Handshaking with remote node..."),
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
            # Increase Threat
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
                    # Update Threat UI
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