// ============================================================
//  RITIK.DEV — Code Portfolio Script
//  Features: Matrix Rain, Live Stats, Tabs, Deep Search,
//            Keyboard Shortcuts, Toast Notifications, Resize
// ============================================================

// --- CONFIG ---
let CONFIG = {
  username: localStorage.getItem('gh_username') || 'Ritik0102-bit',
  repo: localStorage.getItem('gh_repo') || 'Code-Vault',
  token: localStorage.getItem('gh_token') || '',
  branch: 'main'
};

let allFilesFlat = [];
let currentLoadedFile = null;
let openTabs = [];
let activeTabPath = null;
let isResizing = false;
let statsVisible = false;

// --- DOM REFS ---
const fileTreeEl = document.getElementById('fileTree');
const fileCountDisplay = document.getElementById('fileCountDisplay');
const repoNameDisplay = document.getElementById('repoNameDisplay');
const branchDisplay = document.getElementById('branchDisplay');
const searchInput = document.getElementById('searchInput');
const searchModeBadge = document.getElementById('searchModeBadge');
const tabsContainer = document.getElementById('tabsContainer');
const viewerActions = document.getElementById('viewerActions');
const emptyState = document.getElementById('emptyState');
const loader = document.getElementById('loader');
const codeDisplay = document.getElementById('codeDisplay');
const codeElement = document.getElementById('codeElement');
const copyBtn = document.getElementById('copyBtn');
const githubLinkBtn = document.getElementById('githubLinkBtn');
const rawLinkBtn = document.getElementById('rawLinkBtn');
const userAvatar = document.getElementById('userAvatar');
const breadcrumbBar = document.getElementById('breadcrumbBar');
const breadcrumbPath = document.getElementById('breadcrumbPath');
const fileMeta = document.getElementById('fileMeta');
const statsBar = document.getElementById('statsBar');
const appMain = document.querySelector('.app-main');

const settingsBtn = document.getElementById('settingsBtn');
const settingsModal = document.getElementById('settingsModal');
const closeModalBtn = document.getElementById('closeModalBtn');
const closeModalBtn2 = document.getElementById('closeModalBtn2');
const saveConfigBtn = document.getElementById('saveConfigBtn');
const usernameInput = document.getElementById('usernameInput');
const reponameInput = document.getElementById('reponameInput');
const tokenInput = document.getElementById('tokenInput');
const togglePwBtn = document.getElementById('togglePwBtn');

const quickOpenModal = document.getElementById('quickOpenModal');
const quickOpenInput = document.getElementById('quickOpenInput');
const quickOpenResults = document.getElementById('quickOpenResults');

const statsToggleBtn = document.getElementById('statsToggleBtn');
const refreshBtn = document.getElementById('refreshBtn');
const collapseAllBtn = document.getElementById('collapseAllBtn');
const resizeHandle = document.getElementById('resizeHandle');
const sidebar = document.getElementById('sidebar');

// ============================================================
//  MATRIX RAIN CANVAS
// ============================================================
(function initMatrix() {
  const canvas = document.getElementById('matrixCanvas');
  const ctx = canvas.getContext('2d');
  let columns, drops;

  function resize() {
    canvas.width = window.innerWidth;
    canvas.height = window.innerHeight;
    columns = Math.floor(canvas.width / 18);
    drops = Array(columns).fill(1);
  }

  const chars = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789<>/{}[]()#@$%^&*;:=+-|\\~`αβγδεζηθικλμνξπρστυφχψω';

  function draw() {
    ctx.fillStyle = 'rgba(3, 7, 18, 0.04)';
    ctx.fillRect(0, 0, canvas.width, canvas.height);
    ctx.fillStyle = '#00ff88';
    ctx.font = '14px JetBrains Mono, monospace';

    drops.forEach((y, i) => {
      const char = chars[Math.floor(Math.random() * chars.length)];
      const x = i * 18;
      ctx.fillStyle = y === 1 ? '#00ffcc' : '#00ff88';
      ctx.fillText(char, x, y * 18);
      if (y * 18 > canvas.height && Math.random() > 0.975) drops[i] = 0;
      drops[i]++;
    });
  }

  resize();
  window.addEventListener('resize', resize);
  setInterval(draw, 50);
})();

// ============================================================
//  TOAST NOTIFICATIONS
// ============================================================
function showToast(message, type = 'success', duration = 3000) {
  const container = document.getElementById('toastContainer');
  const icons = { success: 'fa-circle-check', error: 'fa-circle-xmark', warning: 'fa-triangle-exclamation', info: 'fa-circle-info' };
  const colors = { success: '#00ff88', error: '#ef4444', warning: '#f59e0b', info: '#00e5ff' };

  const toast = document.createElement('div');
  toast.className = `toast ${type}`;
  toast.style.borderLeftColor = colors[type] || colors.info;
  toast.innerHTML = `<i class="fa-solid ${icons[type] || icons.info}" style="color:${colors[type]};"></i> ${message}`;
  container.appendChild(toast);

  setTimeout(() => {
    toast.style.animation = 'toastOut 0.3s ease forwards';
    setTimeout(() => toast.remove(), 300);
  }, duration);
}

// ============================================================
//  TERMINAL TYPING ANIMATION
// ============================================================
const typingSequences = [
  { cmd: 'git clone github.com/Ritik0102-bit/Code-Vault', output: 'Cloning into Code-Vault... ✓' },
  { cmd: 'ls -la | grep ".cpp\\.py\\.java"', output: '42 files found across 6 languages' },
  { cmd: 'explorer --live --syntax-highlight', output: 'Ready. Select a file to begin →' },
];
let seqIndex = 0;

function runTypingSequence() {
  const typingEl = document.getElementById('typingText');
  const outputEl = document.getElementById('terminalOutput');
  if (!typingEl || !outputEl) return;

  const seq = typingSequences[seqIndex % typingSequences.length];
  typingEl.textContent = '';
  let i = 0;

  const interval = setInterval(() => {
    typingEl.textContent += seq.cmd[i++];
    if (i >= seq.cmd.length) {
      clearInterval(interval);
      setTimeout(() => {
        const line = document.createElement('div');
        line.style.cssText = 'color:var(--neon-cyan);opacity:0;transition:opacity 0.4s ease;';
        line.textContent = '→ ' + seq.output;
        outputEl.appendChild(line);
        requestAnimationFrame(() => { line.style.opacity = '1'; });

        setTimeout(() => {
          typingEl.textContent = '';
          seqIndex++;
          if (outputEl.children.length > 3) outputEl.removeChild(outputEl.firstChild);
          runTypingSequence();
        }, 2500);
      }, 400);
    }
  }, 40);
}

// ============================================================
//  INIT APPLICATION
// ============================================================
document.addEventListener('DOMContentLoaded', () => {
  setupEventListeners();
  initApp();
  runTypingSequence();
});

function setupEventListeners() {
  // Search
  searchInput.addEventListener('input', handleSearch);
  searchInput.addEventListener('keydown', (e) => {
    if (e.key === 'Enter') {
      const q = searchInput.value.trim();
      if (q) handleDeepSearch(q);
    }
  });

  // Copy
  copyBtn.addEventListener('click', copyCodeToClipboard);

  // Stats toggle
  statsToggleBtn.addEventListener('click', toggleStats);

  // Refresh
  refreshBtn.addEventListener('click', () => { initApp(); showToast('Repository refreshed'); });

  // Collapse all folders
  collapseAllBtn.addEventListener('click', () => {
    document.querySelectorAll('.folder-toggle.open').forEach(t => t.classList.remove('open'));
    document.querySelectorAll('.folder-children.open').forEach(c => c.classList.remove('open'));
  });

  // Settings modal
  settingsBtn.addEventListener('click', () => {
    usernameInput.value = CONFIG.username;
    reponameInput.value = CONFIG.repo;
    tokenInput.value = CONFIG.token;
    settingsModal.classList.add('active');
  });

  const closeSettings = () => settingsModal.classList.remove('active');
  closeModalBtn.addEventListener('click', closeSettings);
  closeModalBtn2.addEventListener('click', closeSettings);
  settingsModal.addEventListener('click', (e) => { if (e.target === settingsModal) closeSettings(); });

  // Toggle password visibility
  togglePwBtn.addEventListener('click', () => {
    const isPassword = tokenInput.type === 'password';
    tokenInput.type = isPassword ? 'text' : 'password';
    togglePwBtn.innerHTML = `<i class="fa-solid ${isPassword ? 'fa-eye-slash' : 'fa-eye'}"></i>`;
  });

  // Save config
  saveConfigBtn.addEventListener('click', () => {
    CONFIG.username = usernameInput.value.trim() || 'Ritik0102-bit';
    CONFIG.repo = reponameInput.value.trim() || 'Code-Vault';
    CONFIG.token = tokenInput.value.trim();
    localStorage.setItem('gh_username', CONFIG.username);
    localStorage.setItem('gh_repo', CONFIG.repo);
    localStorage.setItem('gh_token', CONFIG.token);
    settingsModal.classList.remove('active');
    openTabs = [];
    activeTabPath = null;
    initApp();
    showToast('Configuration saved & reloaded!');
  });

  // Quick Open Modal (Ctrl+P)
  quickOpenModal.addEventListener('click', (e) => { if (e.target === quickOpenModal) closeQuickOpen(); });
  quickOpenInput.addEventListener('input', renderQuickOpenResults);
  quickOpenInput.addEventListener('keydown', handleQuickOpenKeys);

  // Keyboard shortcuts
  document.addEventListener('keydown', (e) => {
    const ctrlOrCmd = e.ctrlKey || e.metaKey;

    if (ctrlOrCmd && e.key === 'p') {
      e.preventDefault();
      openQuickOpen();
    }
    if (e.key === 'Escape') {
      if (settingsModal.classList.contains('active')) closeSettings();
      if (quickOpenModal.classList.contains('active')) closeQuickOpen();
    }
    if (ctrlOrCmd && e.key === 'f') {
      e.preventDefault();
      searchInput.focus();
      searchInput.select();
    }
  });

  // Sidebar resize
  resizeHandle.addEventListener('mousedown', startResize);
  document.addEventListener('mousemove', doResize);
  document.addEventListener('mouseup', stopResize);
}

// ============================================================
//  SIDEBAR RESIZE
// ============================================================
function startResize(e) {
  isResizing = true;
  resizeHandle.classList.add('dragging');
  document.body.style.userSelect = 'none';
  document.body.style.cursor = 'col-resize';
}

function doResize(e) {
  if (!isResizing) return;
  const navRect = document.querySelector('.navbar').getBoundingClientRect();
  const newWidth = Math.max(180, Math.min(500, e.clientX));
  sidebar.style.width = newWidth + 'px';
  document.documentElement.style.setProperty('--sidebar-width', newWidth + 'px');
}

function stopResize() {
  isResizing = false;
  resizeHandle.classList.remove('dragging');
  document.body.style.userSelect = '';
  document.body.style.cursor = '';
}

// ============================================================
//  STATS TOGGLE
// ============================================================
function toggleStats() {
  statsVisible = !statsVisible;
  statsBar.classList.toggle('visible', statsVisible);
  appMain.classList.toggle('stats-visible', statsVisible);
  statsToggleBtn.style.color = statsVisible ? 'var(--neon-green)' : '';
}

// ============================================================
//  INIT APP (fetch repo + tree)
// ============================================================
async function initApp() {
  repoNameDisplay.textContent = `${CONFIG.username}/${CONFIG.repo}`;
  if (userAvatar) userAvatar.src = `https://github.com/${CONFIG.username}.png`;

  fileTreeEl.innerHTML = `
    <div class="tree-loading">
      <div class="loading-skeleton"></div>
      <div class="loading-skeleton" style="width:70%;"></div>
      <div class="loading-skeleton" style="width:85%;"></div>
      <div class="loading-skeleton" style="width:60%;"></div>
      <div class="loading-skeleton" style="width:90%;"></div>
    </div>`;

  try {
    const headers = getFetchHeaders();

    // Fetch repo info & tree in parallel
    const [repoRes, treeRes] = await Promise.all([
      fetch(`https://api.github.com/repos/${CONFIG.username}/${CONFIG.repo}`, { headers }),
      fetch(`https://api.github.com/repos/${CONFIG.username}/${CONFIG.repo}/git/trees/HEAD?recursive=1`, { headers })
    ]);

    if (!repoRes.ok) throw new Error(`Repo not found: ${repoRes.status}`);
    if (!treeRes.ok) throw new Error(`Failed to load tree: ${treeRes.status}`);

    const [repoData, treeData] = await Promise.all([repoRes.json(), treeRes.json()]);
    CONFIG.branch = repoData.default_branch || 'main';
    branchDisplay.textContent = CONFIG.branch;

    // Update stats
    document.getElementById('statStars').textContent = formatNumber(repoData.stargazers_count || 0);
    document.getElementById('statForks').textContent = formatNumber(repoData.forks_count || 0);

    const sizeMB = ((repoData.size || 0) / 1024).toFixed(1);
    document.getElementById('statSize').textContent = sizeMB + ' MB';

    // Filter files
    allFilesFlat = treeData.tree.filter(item => {
      const p = item.path;
      return !p.startsWith('.git/') &&
             !p.includes('node_modules/') &&
             !p.includes('.expo/') &&
             !p.endsWith('.exe') &&
             !p.endsWith('.class') &&
             !p.endsWith('.pdb') &&
             !p.endsWith('.png') &&
             !p.endsWith('.jpg') &&
             !p.endsWith('.ico');
    });

    const fileCount = allFilesFlat.filter(i => i.type === 'blob').length;
    fileCountDisplay.textContent = `${fileCount} files`;
    document.getElementById('statFiles').textContent = fileCount;

    renderTree(allFilesFlat);
    renderLangBreakdown();
    fetchLanguages();

  } catch (err) {
    fileTreeEl.innerHTML = `
      <div style="padding:1.25rem;color:#ef4444;font-size:0.82rem;line-height:1.8;">
        <i class="fa-solid fa-triangle-exclamation"></i> <b>Connection Failed</b><br>
        ${err.message}<br>
        <span style="color:var(--text-muted);font-size:0.75rem;">Try adding a GitHub Token in ⚙️ Settings to avoid rate limits.</span>
      </div>`;
    fileCountDisplay.textContent = 'Error';
    showToast('Failed to connect to GitHub API', 'error');
  }
}

function formatNumber(n) {
  if (n >= 1000) return (n / 1000).toFixed(1) + 'k';
  return String(n);
}

function getFetchHeaders() {
  const h = { 'Accept': 'application/vnd.github.v3+json' };
  if (CONFIG.token) h['Authorization'] = `token ${CONFIG.token}`;
  return h;
}

// ============================================================
//  LANGUAGE BREAKDOWN
// ============================================================
const LANG_COLORS = {
  'cpp': '#f34b7d', 'c': '#555555', 'py': '#3572A5', 'java': '#b07219',
  'js': '#f1e05a', 'ts': '#2b7489', 'html': '#e34c26', 'css': '#563d7c',
  'md': '#083fa1', 'json': '#292929', 'sh': '#89e051', 'cs': '#178600',
  'go': '#00ADD8', 'rs': '#dea584', 'kt': '#A97BFF', 'swift': '#F05138',
};

const LANG_NAMES = {
  'cpp': 'C++', 'py': 'Python', 'java': 'Java', 'js': 'JavaScript',
  'ts': 'TypeScript', 'html': 'HTML', 'css': 'CSS', 'md': 'Markdown',
  'c': 'C', 'json': 'JSON', 'sh': 'Shell', 'cs': 'C#', 'go': 'Go',
  'rs': 'Rust', 'kt': 'Kotlin', 'swift': 'Swift',
};

function renderLangBreakdown() {
  const countMap = {};
  allFilesFlat.filter(f => f.type === 'blob').forEach(f => {
    const ext = f.path.split('.').pop().toLowerCase();
    if (LANG_NAMES[ext]) countMap[ext] = (countMap[ext] || 0) + 1;
  });

  const total = Object.values(countMap).reduce((a, b) => a + b, 0);
  if (!total) return;

  const sorted = Object.entries(countMap).sort((a, b) => b[1] - a[1]).slice(0, 6);
  const container = document.getElementById('langBreakdown');
  container.innerHTML = sorted.map(([ext, count]) => {
    const pct = ((count / total) * 100).toFixed(0);
    return `
      <div class="lang-bar-item">
        <div class="lang-color-dot" style="background:${LANG_COLORS[ext] || '#94a3b8'};"></div>
        <span class="lang-name">${LANG_NAMES[ext] || ext.toUpperCase()}</span>
        <span class="lang-pct">${pct}%</span>
      </div>`;
  }).join('');
}

async function fetchLanguages() {
  try {
    const res = await fetch(`https://api.github.com/repos/${CONFIG.username}/${CONFIG.repo}/languages`, {
      headers: getFetchHeaders()
    });
    if (!res.ok) return;
    const langs = await res.json();
    const total = Object.values(langs).reduce((a, b) => a + b, 0);
    if (!total) return;

    const sorted = Object.entries(langs).sort((a, b) => b[1] - a[1]).slice(0, 6);
    const container = document.getElementById('langBreakdown');
    container.innerHTML = sorted.map(([name, bytes]) => {
      const ext = Object.entries(LANG_NAMES).find(([k, v]) => v === name)?.[0];
      const color = ext ? (LANG_COLORS[ext] || '#94a3b8') : '#94a3b8';
      const pct = ((bytes / total) * 100).toFixed(0);
      return `
        <div class="lang-bar-item">
          <div class="lang-color-dot" style="background:${color};"></div>
          <span class="lang-name">${name}</span>
          <span class="lang-pct">${pct}%</span>
        </div>`;
    }).join('');
  } catch (_) { /* silently ignore */ }
}

// ============================================================
//  FILE TREE
// ============================================================
function renderTree(items) {
  fileTreeEl.innerHTML = '';
  const root = {};

  items.forEach(item => {
    const parts = item.path.split('/');
    let curr = root;
    parts.forEach((part, idx) => {
      if (!curr[part]) {
        curr[part] = {
          __name: part,
          __path: parts.slice(0, idx + 1).join('/'),
          __type: idx === parts.length - 1 ? item.type : 'tree',
          __children: {}
        };
      }
      curr = curr[part].__children;
    });
  });

  const frag = document.createDocumentFragment();
  buildDOMTree(root, frag, 0);
  fileTreeEl.appendChild(frag);
}

function getFileIcon(filename, type) {
  if (type === 'tree') return '<i class="fa-solid fa-folder" style="color:#60a5fa;"></i>';
  const ext = filename.split('.').pop().toLowerCase();
  const iconMap = {
    'cpp': '<i class="devicon-cplusplus-plain colored"></i>',
    'c': '<i class="devicon-c-plain colored"></i>',
    'py': '<i class="devicon-python-plain colored"></i>',
    'java': '<i class="devicon-java-plain colored"></i>',
    'js': '<i class="devicon-javascript-plain colored"></i>',
    'ts': '<i class="devicon-typescript-plain colored"></i>',
    'html': '<i class="devicon-html5-plain colored"></i>',
    'css': '<i class="devicon-css3-plain colored"></i>',
    'md': '<i class="devicon-markdown-original" style="color:#38bdf8;"></i>',
    'json': '<i class="fa-solid fa-brackets-curly" style="color:#94a3b8;"></i>',
    'go': '<i class="devicon-go-plain colored"></i>',
    'rs': '<i class="devicon-rust-original colored"></i>',
    'sh': '<i class="fa-solid fa-terminal" style="color:#89e051;"></i>',
    'kt': '<i class="devicon-kotlin-plain colored"></i>',
    'swift': '<i class="devicon-swift-plain colored"></i>',
    'cs': '<i class="devicon-csharp-plain colored"></i>',
  };
  return iconMap[ext] || '<i class="fa-regular fa-file-code" style="color:#64748b;"></i>';
}

function buildDOMTree(nodeObj, parentEl, depth) {
  const keys = Object.keys(nodeObj).sort((a, b) => {
    if (nodeObj[a].__type === 'tree' && nodeObj[b].__type !== 'tree') return -1;
    if (nodeObj[a].__type !== 'tree' && nodeObj[b].__type === 'tree') return 1;
    return a.localeCompare(b);
  });

  keys.forEach(key => {
    const data = nodeObj[key];
    const el = document.createElement('div');
    const icon = getFileIcon(data.__name, data.__type);

    if (data.__type === 'tree') {
      el.className = 'tree-item folder';
      el.style.paddingLeft = `${depth * 14 + 10}px`;
      el.innerHTML = `<span class="folder-toggle">▶</span> <span class="icon">${icon}</span> <span>${data.__name}</span>`;

      const childrenEl = document.createElement('div');
      childrenEl.className = 'folder-children';

      el.addEventListener('click', () => {
        el.querySelector('.folder-toggle').classList.toggle('open');
        childrenEl.classList.toggle('open');
      });

      parentEl.appendChild(el);
      buildDOMTree(data.__children, childrenEl, depth + 1);
      parentEl.appendChild(childrenEl);
    } else {
      el.className = 'tree-item file';
      el.style.paddingLeft = `${depth * 14 + 24}px`;
      el.innerHTML = `<span class="icon">${icon}</span> <span>${data.__name}</span>`;
      el.title = data.__path;
      if (data.__path === activeTabPath) el.classList.add('active');
      el.addEventListener('click', () => loadFileContent(data.__path));
      parentEl.appendChild(el);
    }
  });
}

// ============================================================
//  TABS
// ============================================================
function renderTabs() {
  if (!tabsContainer) return;
  tabsContainer.innerHTML = '';

  if (openTabs.length === 0) {
    emptyState.style.display = 'flex';
    codeDisplay.style.display = 'none';
    viewerActions.style.display = 'none';
    loader.style.display = 'none';
    breadcrumbBar.style.display = 'none';
    return;
  }

  openTabs.forEach(tab => {
    const filename = tab.path.split('/').pop();
    const icon = getFileIcon(filename, 'blob');
    const el = document.createElement('div');
    el.className = `file-tab ${tab.path === activeTabPath ? 'active' : ''}`;
    el.innerHTML = `<span class="icon">${icon}</span><span>${filename}</span><span class="tab-close" title="Close"><i class="fa-solid fa-xmark"></i></span>`;
    el.addEventListener('click', () => switchTab(tab.path));
    el.querySelector('.tab-close').addEventListener('click', e => { e.stopPropagation(); closeTab(tab.path); });
    tabsContainer.appendChild(el);
  });

  const activeEl = tabsContainer.querySelector('.file-tab.active');
  if (activeEl) activeEl.scrollIntoView({ behavior: 'smooth', block: 'nearest', inline: 'nearest' });
}

function switchTab(filePath) {
  activeTabPath = filePath;
  currentLoadedFile = filePath;
  renderTabs();
  highlightSidebarFile(filePath);

  const tab = openTabs.find(t => t.path === filePath);
  if (!tab) return;

  if (tab.loading) {
    emptyState.style.display = 'none';
    codeDisplay.style.display = 'none';
    viewerActions.style.display = 'none';
    loader.style.display = 'flex';
    return;
  }

  if (tab.content !== null) displayCodeContent(tab.path, tab.content);
}

function closeTab(filePath) {
  const idx = openTabs.findIndex(t => t.path === filePath);
  if (idx !== -1) openTabs.splice(idx, 1);

  if (activeTabPath === filePath) {
    if (openTabs.length > 0) {
      switchTab(openTabs[Math.max(0, idx - 1)].path);
    } else {
      activeTabPath = null;
      currentLoadedFile = null;
      renderTabs();
      document.querySelectorAll('.tree-item.active').forEach(i => i.classList.remove('active'));
    }
  } else {
    renderTabs();
  }
}

function highlightSidebarFile(filePath) {
  document.querySelectorAll('.tree-item.file').forEach(item => {
    item.classList.toggle('active', item.title === filePath);
  });
}

// ============================================================
//  DISPLAY CODE CONTENT
// ============================================================
function displayCodeContent(filePath, text) {
  emptyState.style.display = 'none';
  loader.style.display = 'none';
  codeDisplay.style.display = 'block';
  viewerActions.style.display = 'flex';
  breadcrumbBar.style.display = 'flex';

  const filename = filePath.split('/').pop();
  const rawUrl = `https://raw.githubusercontent.com/${CONFIG.username}/${CONFIG.repo}/${CONFIG.branch}/${filePath}`;
  githubLinkBtn.href = `https://github.com/${CONFIG.username}/${CONFIG.repo}/blob/${CONFIG.branch}/${filePath}`;
  rawLinkBtn.href = rawUrl;

  // Breadcrumb
  const parts = filePath.split('/');
  breadcrumbPath.innerHTML = parts.map((p, i) => {
    const isLast = i === parts.length - 1;
    const icon = isLast ? getFileIcon(p, 'blob') : '<i class="fa-solid fa-folder" style="color:#60a5fa;font-size:0.7rem;"></i>';
    return `
      ${i > 0 ? '<span class="breadcrumb-sep">/</span>' : ''}
      <span class="breadcrumb-segment ${isLast ? 'last' : ''}">${icon} ${p}</span>`;
  }).join('');

  // File meta (line count, size)
  const lineCount = text.split('\n').length;
  const sizeKB = (new Blob([text]).size / 1024).toFixed(1);
  const ext = filename.split('.').pop().toLowerCase();
  fileMeta.innerHTML = `
    <span><i class="fa-solid fa-lines-lean-code"></i> ${lineCount} lines</span>
    <span><i class="fa-solid fa-weight-scale"></i> ${sizeKB} KB</span>
    <span><i class="fa-solid fa-code"></i> ${ext.toUpperCase()}</span>`;

  // Syntax highlight
  codeElement.textContent = text;
  const langMap = {
    'cpp': 'cpp', 'c': 'c', 'py': 'python', 'java': 'java',
    'js': 'javascript', 'jsx': 'jsx', 'ts': 'typescript', 'tsx': 'tsx',
    'html': 'html', 'css': 'css', 'json': 'json', 'md': 'markdown',
    'sh': 'bash', 'go': 'go', 'rs': 'rust', 'cs': 'csharp', 'kt': 'kotlin',
  };
  codeElement.className = `language-${langMap[ext] || 'clike'}`;
  if (window.Prism) Prism.highlightElement(codeElement);
}

// ============================================================
//  LOAD FILE
// ============================================================
async function loadFileContent(filePath) {
  let tab = openTabs.find(t => t.path === filePath);

  if (!tab) {
    tab = { path: filePath, content: null, loading: true };
    openTabs.push(tab);
  }

  switchTab(filePath);

  if (tab.content !== null) {
    displayCodeContent(filePath, tab.content);
    return;
  }

  try {
    const rawUrl = `https://raw.githubusercontent.com/${CONFIG.username}/${CONFIG.repo}/${CONFIG.branch}/${filePath}`;
    const res = await fetch(rawUrl);
    if (!res.ok) throw new Error(`HTTP ${res.status}`);
    const text = await res.text();

    tab.content = text;
    tab.loading = false;

    if (activeTabPath === filePath) displayCodeContent(filePath, text);
    showToast(`Loaded: ${filePath.split('/').pop()}`, 'success', 2000);

  } catch (err) {
    tab.loading = false;
    if (activeTabPath === filePath) {
      loader.style.display = 'none';
      emptyState.style.display = 'flex';
      emptyState.innerHTML = `
        <div style="text-align:center;">
          <div style="font-size:3rem;color:#ef4444;">⚠️</div>
          <h2 style="margin:1rem 0 0.5rem;">Error Loading File</h2>
          <p style="color:var(--text-muted);">${err.message}</p>
        </div>`;
    }
    showToast(`Failed to load file: ${err.message}`, 'error');
  }
}

function quickLoadFile(path) {
  loadFileContent(path);
}

// ============================================================
//  COPY CODE
// ============================================================
function copyCodeToClipboard() {
  if (!codeElement.textContent) return;
  navigator.clipboard.writeText(codeElement.textContent).then(() => {
    const orig = copyBtn.innerHTML;
    copyBtn.innerHTML = '<i class="fa-solid fa-check" style="color:#00ff88;"></i> Copied!';
    copyBtn.style.color = 'var(--neon-green)';
    showToast('Code copied to clipboard!', 'success', 1500);
    setTimeout(() => { copyBtn.innerHTML = orig; copyBtn.style.color = ''; }, 2000);
  });
}

// ============================================================
//  SEARCH (file name)
// ============================================================
function handleSearch(e) {
  const query = e.target.value.toLowerCase().trim();
  searchModeBadge.textContent = 'FILE';
  searchModeBadge.style.background = '';
  searchModeBadge.style.color = '';

  if (!query) { renderTree(allFilesFlat); return; }

  const filtered = allFilesFlat.filter(item => item.path.toLowerCase().includes(query));
  fileTreeEl.innerHTML = '';

  if (filtered.length === 0) {
    fileTreeEl.innerHTML = `<div style="padding:1rem;color:var(--text-muted);font-size:0.8rem;">No matching files.<br><span style="color:var(--neon-green);">Press Enter to search inside code.</span></div>`;
    return;
  }

  const frag = document.createDocumentFragment();
  filtered.filter(i => i.type === 'blob').forEach(item => {
    const el = document.createElement('div');
    el.className = 'tree-item file';
    el.style.paddingLeft = '1rem';
    const icon = getFileIcon(item.path, 'blob');
    el.innerHTML = `<span class="icon">${icon}</span> <span style="overflow:hidden;text-overflow:ellipsis;">${item.path}</span>`;
    if (item.path === activeTabPath) el.classList.add('active');
    el.addEventListener('click', () => loadFileContent(item.path));
    frag.appendChild(el);
  });
  fileTreeEl.appendChild(frag);
}

// ============================================================
//  DEEP CODE SEARCH
// ============================================================
async function handleDeepSearch(query) {
  searchModeBadge.textContent = 'SCANNING';
  searchModeBadge.style.background = 'rgba(245,158,11,0.15)';
  searchModeBadge.style.color = '#f59e0b';

  fileTreeEl.innerHTML = `<div style="padding:1rem;color:var(--text-muted);font-size:0.8rem;"><i class="fa-solid fa-spinner fa-spin"></i> Scanning code files...</div>`;

  try {
    const res = await fetch(
      `https://api.github.com/search/code?q=${encodeURIComponent(query)}+repo:${CONFIG.username}/${CONFIG.repo}`,
      { headers: getFetchHeaders() }
    );
    if (!res.ok) throw new Error('Rate limit or search error');
    const data = await res.json();

    searchModeBadge.textContent = `${data.items.length} FOUND`;
    searchModeBadge.style.background = 'rgba(0,255,136,0.12)';
    searchModeBadge.style.color = 'var(--neon-green)';

    fileTreeEl.innerHTML = '';
    if (data.items.length === 0) {
      fileTreeEl.innerHTML = `<div style="padding:1rem;color:var(--text-muted);font-size:0.8rem;">No code matches for "${query}".</div>`;
      return;
    }

    const frag = document.createDocumentFragment();
    data.items.forEach(item => {
      const el = document.createElement('div');
      el.className = 'tree-item file';
      el.style.paddingLeft = '1rem';
      const icon = getFileIcon(item.path, 'blob');
      el.innerHTML = `<span class="icon">${icon}</span> <span style="overflow:hidden;text-overflow:ellipsis;">${item.path}</span>`;
      el.title = `Match found in ${item.path}`;
      if (item.path === activeTabPath) el.classList.add('active');
      el.addEventListener('click', () => loadFileContent(item.path));
      frag.appendChild(el);
    });
    fileTreeEl.appendChild(frag);
    showToast(`Found "${query}" in ${data.items.length} file(s)`, 'info');

  } catch (err) {
    searchModeBadge.textContent = 'FILE';
    searchModeBadge.style.background = '';
    searchModeBadge.style.color = '';
    fileTreeEl.innerHTML = `<div style="padding:1rem;color:#ef4444;font-size:0.8rem;">⚠️ Deep search failed or rate-limited.</div>`;
    showToast('Deep search failed — try adding a GitHub Token', 'error');
    handleSearch({ target: { value: query } });
  }
}

// ============================================================
//  QUICK OPEN (Ctrl+P)
// ============================================================
let quickOpenSelectedIndex = -1;

function openQuickOpen() {
  quickOpenModal.classList.add('active');
  quickOpenInput.value = '';
  quickOpenResults.innerHTML = '';
  quickOpenSelectedIndex = -1;
  setTimeout(() => quickOpenInput.focus(), 50);
}

function closeQuickOpen() {
  quickOpenModal.classList.remove('active');
}

function renderQuickOpenResults() {
  const query = quickOpenInput.value.toLowerCase().trim();
  quickOpenSelectedIndex = -1;

  const files = allFilesFlat.filter(f => f.type === 'blob');
  const filtered = query
    ? files.filter(f => f.path.toLowerCase().includes(query)).slice(0, 20)
    : files.slice(0, 20);

  quickOpenResults.innerHTML = '';
  filtered.forEach((item, idx) => {
    const filename = item.path.split('/').pop();
    const dir = item.path.includes('/') ? item.path.substring(0, item.path.lastIndexOf('/')) : '';
    const icon = getFileIcon(filename, 'blob');
    const el = document.createElement('div');
    el.className = 'qo-item';
    el.innerHTML = `<span>${icon}</span><span>${filename}</span><span class="qo-item-path">${dir}</span>`;
    el.addEventListener('click', () => {
      closeQuickOpen();
      loadFileContent(item.path);
    });
    quickOpenResults.appendChild(el);
  });
}

function handleQuickOpenKeys(e) {
  const items = quickOpenResults.querySelectorAll('.qo-item');
  if (e.key === 'ArrowDown') {
    e.preventDefault();
    quickOpenSelectedIndex = Math.min(quickOpenSelectedIndex + 1, items.length - 1);
  } else if (e.key === 'ArrowUp') {
    e.preventDefault();
    quickOpenSelectedIndex = Math.max(quickOpenSelectedIndex - 1, -1);
  } else if (e.key === 'Enter') {
    if (quickOpenSelectedIndex >= 0 && items[quickOpenSelectedIndex]) {
      items[quickOpenSelectedIndex].click();
    } else if (items[0]) {
      items[0].click();
    }
    return;
  } else if (e.key === 'Escape') {
    closeQuickOpen();
    return;
  }

  items.forEach((item, i) => item.classList.toggle('selected', i === quickOpenSelectedIndex));
  if (items[quickOpenSelectedIndex]) {
    items[quickOpenSelectedIndex].scrollIntoView({ block: 'nearest' });
  }
}
