// Configuration Defaults
let CONFIG = {
  username: localStorage.getItem('gh_username') || 'Ritik0102-bit',
  repo: localStorage.getItem('gh_repo') || 'CODE',
  token: localStorage.getItem('gh_token') || '',
  branch: 'main'
};

let allFilesFlat = [];
let currentLoadedFile = null;
let openTabs = []; // Array of { path, content, loading }
let activeTabPath = null;

// DOM Elements
const fileTreeEl = document.getElementById('fileTree');
const fileCountDisplay = document.getElementById('fileCountDisplay');
const repoNameDisplay = document.getElementById('repoNameDisplay');
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

// Settings Elements
const settingsBtn = document.getElementById('settingsBtn');
const settingsModal = document.getElementById('settingsModal');
const closeModalBtn = document.getElementById('closeModalBtn');
const saveConfigBtn = document.getElementById('saveConfigBtn');
const usernameInput = document.getElementById('usernameInput');
const reponameInput = document.getElementById('reponameInput');
const tokenInput = document.getElementById('tokenInput');

// Initialize Application
document.addEventListener('DOMContentLoaded', () => {
  initApp();
  setupEventListeners();
});

function setupEventListeners() {
  searchInput.addEventListener('input', handleSearch);
  searchInput.addEventListener('keydown', (e) => {
    if (e.key === 'Enter') {
      const query = searchInput.value.trim();
      if (query) {
        handleDeepSearch(query);
      }
    }
  });

  copyBtn.addEventListener('click', copyCodeToClipboard);
  
  settingsBtn.addEventListener('click', () => {
    usernameInput.value = CONFIG.username;
    reponameInput.value = CONFIG.repo;
    tokenInput.value = CONFIG.token;
    settingsModal.classList.add('active');
  });

  closeModalBtn.addEventListener('click', () => {
    settingsModal.classList.remove('active');
  });

  saveConfigBtn.addEventListener('click', () => {
    CONFIG.username = usernameInput.value.trim() || 'Ritik0102-bit';
    CONFIG.repo = reponameInput.value.trim() || 'CODE';
    CONFIG.token = tokenInput.value.trim();

    localStorage.setItem('gh_username', CONFIG.username);
    localStorage.setItem('gh_repo', CONFIG.repo);
    localStorage.setItem('gh_token', CONFIG.token);

    settingsModal.classList.remove('active');
    initApp();
  });
}

function getFetchHeaders() {
  const headers = { 'Accept': 'application/vnd.github.v3+json' };
  if (CONFIG.token) {
    headers['Authorization'] = `token ${CONFIG.token}`;
  }
  return headers;
}

async function initApp() {
  repoNameDisplay.textContent = `${CONFIG.username}/${CONFIG.repo}`;
  if (userAvatar) {
    userAvatar.src = `https://github.com/${CONFIG.username}.png`;
  }
  
  fileTreeEl.innerHTML = `<div style="padding: 1rem; color: var(--text-muted); font-size: 0.85rem;"><i class="fa-solid fa-spinner fa-spin"></i> Connecting to GitHub API...</div>`;
  
  try {
    const repoRes = await fetch(`https://api.github.com/repos/${CONFIG.username}/${CONFIG.repo}`, {
      headers: getFetchHeaders()
    });
    
    if (!repoRes.ok) {
      throw new Error(`GitHub API Error: ${repoRes.status} ${repoRes.statusText}`);
    }
    
    const repoData = await repoRes.json();
    CONFIG.branch = repoData.default_branch || 'main';

    const treeRes = await fetch(`https://api.github.com/repos/${CONFIG.username}/${CONFIG.repo}/git/trees/${CONFIG.branch}?recursive=1`, {
      headers: getFetchHeaders()
    });

    if (!treeRes.ok) {
      throw new Error(`Failed to load repository files.`);
    }

    const treeData = await treeRes.json();
    
    allFilesFlat = treeData.tree.filter(item => {
      const path = item.path;
      return !path.startsWith('.git/') && 
             !path.includes('node_modules/') && 
             !path.includes('.expo/') && 
             !path.endsWith('.exe') && 
             !path.endsWith('.class') &&
             !path.endsWith('.pdb');
    });

    const fileOnlyCount = allFilesFlat.filter(i => i.type === 'blob').length;
    fileCountDisplay.textContent = `${fileOnlyCount} files`;

    renderTree(allFilesFlat);

  } catch (err) {
    fileTreeEl.innerHTML = `
      <div style="padding: 1rem; color: #ef4444; font-size: 0.85rem;">
        ⚠️ <b>Connection Failed</b><br><br>
        ${err.message}<br><br>
        <span style="color: var(--text-muted);">Tip: If API rate limit exceeded, click ⚙️ to add a GitHub token or check repo username.</span>
      </div>
    `;
    fileCountDisplay.textContent = 'Error';
  }
}

// Build & Render Folder Tree
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
  if (type === 'tree') return '<i class="fa-solid fa-folder" style="color: #60a5fa;"></i>';
  if (filename.endsWith('.cpp')) return '<i class="devicon-cplusplus-plain colored"></i>';
  if (filename.endsWith('.c')) return '<i class="devicon-c-plain colored"></i>';
  if (filename.endsWith('.py')) return '<i class="devicon-python-plain colored"></i>';
  if (filename.endsWith('.java')) return '<i class="devicon-java-plain colored"></i>';
  if (filename.endsWith('.js')) return '<i class="devicon-javascript-plain colored"></i>';
  if (filename.endsWith('.html')) return '<i class="devicon-html5-plain colored"></i>';
  if (filename.endsWith('.css')) return '<i class="devicon-css3-plain colored"></i>';
  if (filename.endsWith('.md')) return '<i class="devicon-markdown-original" style="color: #38bdf8;"></i>';
  if (filename.endsWith('.json')) return '<i class="fa-solid fa-gear" style="color: #94a3b8;"></i>';
  return '<i class="fa-regular fa-file-code" style="color: #94a3b8;"></i>';
}

function buildDOMTree(nodeObj, parentEl, depth) {
  const keys = Object.keys(nodeObj).sort((a, b) => {
    const typeA = nodeObj[a].__type;
    const typeB = nodeObj[b].__type;
    if (typeA === 'tree' && typeB !== 'tree') return -1;
    if (typeA !== 'tree' && typeB === 'tree') return 1;
    return a.localeCompare(b);
  });

  keys.forEach(key => {
    const data = nodeObj[key];
    const el = document.createElement('div');
    const icon = getFileIcon(data.__name, data.__type);

    if (data.__type === 'tree') {
      el.className = 'tree-item folder';
      el.style.paddingLeft = `${depth * 14 + 12}px`;
      el.innerHTML = `<span class="folder-toggle">▶</span> <span class="icon">${icon}</span> <span>${data.__name}</span>`;
      
      const childrenContainer = document.createElement('div');
      childrenContainer.className = 'folder-children';
      
      el.addEventListener('click', () => {
        const toggle = el.querySelector('.folder-toggle');
        toggle.classList.toggle('open');
        childrenContainer.classList.toggle('open');
      });

      parentEl.appendChild(el);
      buildDOMTree(data.__children, childrenContainer, depth + 1);
      parentEl.appendChild(childrenContainer);
    } else {
      el.className = 'tree-item file';
      el.style.paddingLeft = `${depth * 14 + 26}px`;
      el.innerHTML = `<span class="icon">${icon}</span> <span>${data.__name}</span>`;
      el.title = data.__path;
      if (data.__path === activeTabPath) el.classList.add('active');
      
      el.addEventListener('click', () => {
        loadFileContent(data.__path);
      });

      parentEl.appendChild(el);
    }
  });
}

// Multi-Tab UI Rendering
function renderTabs() {
  if (!tabsContainer) return;
  tabsContainer.innerHTML = '';

  if (openTabs.length === 0) {
    emptyState.style.display = 'flex';
    codeDisplay.style.display = 'none';
    viewerActions.style.display = 'none';
    loader.style.display = 'none';
    return;
  }

  openTabs.forEach(tab => {
    const filename = tab.path.split('/').pop();
    const icon = getFileIcon(filename, 'blob');
    const el = document.createElement('div');
    el.className = `file-tab ${tab.path === activeTabPath ? 'active' : ''}`;
    el.innerHTML = `<span>${icon}</span> <span>${filename}</span> <span class="tab-close" title="Close"><i class="fa-solid fa-xmark"></i></span>`;
    
    el.addEventListener('click', () => switchTab(tab.path));
    
    const closeBtn = el.querySelector('.tab-close');
    closeBtn.addEventListener('click', (e) => {
      e.stopPropagation();
      closeTab(tab.path);
    });

    tabsContainer.appendChild(el);
  });

  // Ensure active tab scrolled into view
  const activeTabEl = tabsContainer.querySelector('.file-tab.active');
  if (activeTabEl) {
    activeTabEl.scrollIntoView({ behavior: 'smooth', block: 'nearest', inline: 'nearest' });
  }
}

function switchTab(filePath) {
  activeTabPath = filePath;
  currentLoadedFile = filePath;
  renderTabs();

  // Update explorer highlight
  document.querySelectorAll('.tree-item.file').forEach(item => {
    if (item.title === filePath) item.classList.add('active');
    else item.classList.remove('active');
  });

  const tab = openTabs.find(t => t.path === filePath);
  if (!tab) return;

  if (tab.loading) {
    emptyState.style.display = 'none';
    codeDisplay.style.display = 'none';
    viewerActions.style.display = 'none';
    loader.style.display = 'flex';
    return;
  }

  if (tab.content !== null) {
    displayCodeContent(tab.path, tab.content);
  }
}

function closeTab(filePath) {
  const idx = openTabs.findIndex(t => t.path === filePath);
  if (idx !== -1) {
    openTabs.splice(idx, 1);
  }

  if (activeTabPath === filePath) {
    if (openTabs.length > 0) {
      const nextIdx = Math.max(0, idx - 1);
      switchTab(openTabs[nextIdx].path);
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

function displayCodeContent(filePath, text) {
  emptyState.style.display = 'none';
  loader.style.display = 'none';
  codeDisplay.style.display = 'block';
  viewerActions.style.display = 'flex';

  const filename = filePath.split('/').pop();
  const rawUrl = `https://raw.githubusercontent.com/${CONFIG.username}/${CONFIG.repo}/${CONFIG.branch}/${filePath}`;
  githubLinkBtn.href = `https://github.com/${CONFIG.username}/${CONFIG.repo}/blob/${CONFIG.branch}/${filePath}`;
  rawLinkBtn.href = rawUrl;

  codeElement.textContent = text;
  const ext = filename.split('.').pop().toLowerCase();
  const langMap = {
    'cpp': 'cpp', 'c': 'c', 'py': 'python', 'java': 'java',
    'js': 'javascript', 'jsx': 'jsx', 'ts': 'typescript',
    'html': 'html', 'css': 'css', 'json': 'json', 'md': 'markdown'
  };
  const prismLang = langMap[ext] || 'clike';
  codeElement.className = `language-${prismLang}`;

  if (window.Prism) {
    Prism.highlightElement(codeElement);
  }
}

// Load & Display File Content
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
    if (!res.ok) throw new Error('Failed to fetch raw content');
    const text = await res.text();

    tab.content = text;
    tab.loading = false;

    if (activeTabPath === filePath) {
      displayCodeContent(filePath, text);
    }
  } catch (err) {
    tab.loading = false;
    if (activeTabPath === filePath) {
      loader.style.display = 'none';
      emptyState.style.display = 'flex';
      emptyState.innerHTML = `
        <div class="empty-icon">⚠️</div>
        <h2>Error Loading File</h2>
        <p>Could not fetch file content from GitHub: ${err.message}</p>
      `;
    }
  }
}

function quickLoadFile(path) {
  loadFileContent(path);
}

function copyCodeToClipboard() {
  if (!codeElement.textContent) return;
  navigator.clipboard.writeText(codeElement.textContent).then(() => {
    const originalText = copyBtn.innerHTML;
    copyBtn.innerHTML = `<i class="fa-solid fa-check" style="color:#10b981;"></i> Copied!`;
    copyBtn.style.color = '#10b981';
    setTimeout(() => {
      copyBtn.innerHTML = originalText;
      copyBtn.style.color = '';
    }, 2000);
  });
}

// Search Filter (By File Name)
function handleSearch(e) {
  const query = e.target.value.toLowerCase().trim();
  searchModeBadge.textContent = 'File Search';
  searchModeBadge.style.background = '';
  searchModeBadge.style.color = '';

  if (!query) {
    renderTree(allFilesFlat);
    return;
  }

  const filtered = allFilesFlat.filter(item => item.path.toLowerCase().includes(query));
  
  fileTreeEl.innerHTML = '';
  if (filtered.length === 0) {
    fileTreeEl.innerHTML = `<div style="padding: 1rem; color: var(--text-muted); font-size: 0.85rem;">No matching files found.<br><br><span style="color:var(--accent-cyan);">💡 Tip: Press <b>Enter</b> to search inside code contents!</span></div>`;
    return;
  }

  const frag = document.createDocumentFragment();
  filtered.forEach(item => {
    if (item.type === 'blob') {
      const el = document.createElement('div');
      el.className = 'tree-item file';
      el.style.paddingLeft = `1rem`;
      const icon = getFileIcon(item.path, 'blob');
      el.innerHTML = `<span class="icon">${icon}</span> <span style="overflow:hidden; text-overflow:ellipsis;">${item.path}</span>`;
      if (item.path === activeTabPath) el.classList.add('active');
      el.addEventListener('click', () => {
        loadFileContent(item.path);
      });
      frag.appendChild(el);
    }
  });
  fileTreeEl.appendChild(frag);
}

// Deep Code Search (Inside File Contents via GitHub API)
async function handleDeepSearch(query) {
  searchModeBadge.textContent = 'Deep Searching...';
  searchModeBadge.style.background = 'rgba(245, 158, 11, 0.2)';
  searchModeBadge.style.color = '#f59e0b';

  fileTreeEl.innerHTML = `<div style="padding: 1rem; color: var(--text-muted); font-size: 0.85rem;"><i class="fa-solid fa-spinner fa-spin"></i> Searching inside code files across repo...</div>`;

  try {
    const res = await fetch(`https://api.github.com/search/code?q=${encodeURIComponent(query)}+repo:${CONFIG.username}/${CONFIG.repo}`, {
      headers: getFetchHeaders()
    });
    
    if (!res.ok) throw new Error('API Rate limit or search error');
    const data = await res.json();
    
    searchModeBadge.textContent = `Found ${data.items.length} inside files`;
    searchModeBadge.style.background = 'rgba(16, 185, 129, 0.2)';
    searchModeBadge.style.color = '#10b981';

    fileTreeEl.innerHTML = '';
    if (data.items.length === 0) {
      fileTreeEl.innerHTML = `<div style="padding: 1rem; color: var(--text-muted); font-size: 0.85rem;">No code matches found for "${query}".</div>`;
      return;
    }

    const frag = document.createDocumentFragment();
    data.items.forEach(item => {
      const el = document.createElement('div');
      el.className = 'tree-item file';
      el.style.paddingLeft = `1rem`;
      const icon = getFileIcon(item.path, 'blob');
      el.innerHTML = `<span class="icon">${icon}</span> <span style="overflow:hidden; text-overflow:ellipsis;">${item.path}</span>`;
      el.title = `Matched code inside ${item.path}`;
      if (item.path === activeTabPath) el.classList.add('active');
      el.addEventListener('click', () => {
        loadFileContent(item.path);
      });
      frag.appendChild(el);
    });
    fileTreeEl.appendChild(frag);

  } catch (err) {
    searchModeBadge.textContent = 'File Search';
    searchModeBadge.style.background = '';
    searchModeBadge.style.color = '';
    fileTreeEl.innerHTML = `<div style="padding: 1rem; color: #ef4444; font-size: 0.85rem;">⚠️ Deep search failed or rate-limited. Searching by file name instead.</div>`;
    handleSearch({ target: { value: query } });
  }
}
