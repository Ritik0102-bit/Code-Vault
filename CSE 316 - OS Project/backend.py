"""
Security Vulnerability Detection Framework - Backend
A comprehensive system for detecting and mitigating security vulnerabilities

!!! WARNING: THIS CODE EXECUTES REAL SYSTEM COMMANDS FOR MITIGATION !!!
It MUST be run with elevated privileges (root/administrator) to function.
Running this on a non-isolated system is a severe security risk.
"""

from flask import Flask, jsonify, request
from flask_cors import CORS
import psutil
import os
import re
import hashlib
import subprocess
import socket
import threading
import time
from datetime import datetime
from collections import defaultdict
import json

app = Flask(__name__)
# Enable CORS for frontend running on a different port (like PyCharm's live server)
CORS(app)

# Global storage for vulnerabilities and logs
vulnerabilities_db = []
system_logs = []
scan_status = {"scanning": False, "progress": 0}
mitigation_history = []


class VulnerabilityScanner:
    def __init__(self):
        self.scan_results = []

    def check_buffer_overflow_vulnerabilities(self):
        """Detect potential buffer overflow vulnerabilities (Simulated risk check)"""
        vulns = []

        # Check for unsafe C functions in system binaries
        unsafe_functions = ['strcpy', 'strcat', 'gets', 'sprintf', 'scanf']

        try:
            # Scan common binary directories
            binary_paths = ['/usr/bin', '/usr/sbin', '/bin', '/sbin']

            for path in binary_paths:
                if os.path.exists(path):
                    # NOTE: Limiting scan depth for demo/speed
                    for file in os.listdir(path)[:10]:
                        file_path = os.path.join(path, file)
                        if os.path.isfile(file_path):
                            try:
                                result = subprocess.run(
                                    ['strings', file_path],
                                    capture_output=True,
                                    text=True,
                                    timeout=2
                                )
                                for func in unsafe_functions:
                                    if func in result.stdout:
                                        vulns.append({
                                            'name': f'Buffer Overflow Risk in {file}',
                                            'severity': 'high',
                                            'description': f'Binary uses unsafe function: {func}',
                                            'location': file_path,
                                            # Mock CVE for demonstration
                                            'cve': f'CVE-2024-{abs(hash(file_path)) % 10000}',
                                            'mitigation': 'Replace unsafe functions with bounds-checked alternatives',
                                            'impact': 'Potential memory corruption and code execution',
                                            'category': 'buffer_overflow'
                                        })
                                        break
                            except:
                                pass
        except Exception as e:
            print(f"Buffer overflow scan error: {e}")

        return vulns[:3]  # Return top 3

    def check_privilege_escalation(self):
        """Check for SUID/SGID binaries (Real config check)"""
        vulns = []

        try:
            # Check for SUID/SGID binaries
            result = subprocess.run(
                ['find', '/usr', '-perm', '-4000', '-o', '-perm', '-2000'],
                capture_output=True,
                text=True,
                timeout=10
            )

            suid_files = result.stdout.strip().split('\n')[:5]

            for file in suid_files:
                if file and os.path.exists(file):
                    vulns.append({
                        'name': 'SUID Binary Detected',
                        'severity': 'critical',
                        'description': f'SUID/SGID bit set on {os.path.basename(file)}',
                        'location': file,
                        'cve': f'CVE-2024-{abs(hash(file)) % 10000}',
                        'mitigation': 'Review necessity of SUID bit, implement proper authorization',
                        'impact': 'Potential privilege escalation to root',
                        'category': 'privilege_escalation'
                    })
        except Exception as e:
            print(f"Privilege escalation scan error: {e}")

        return vulns[:2]  # Return top 2

    def check_network_vulnerabilities(self):
        """Check for network-related vulnerabilities (Real config check)"""
        vulns = []

        try:
            # Check open ports
            connections = psutil.net_connections()
            listening_ports = {}  # Store port and process info

            for conn in connections:
                if conn.status == 'LISTEN' and conn.laddr and conn.pid:
                    try:
                        proc = psutil.Process(conn.pid)
                        listening_ports[conn.laddr.port] = {'proc': proc.name(), 'laddr': conn.laddr.ip}
                    except psutil.NoSuchProcess:
                        continue

            # Common vulnerable ports
            dangerous_ports = {
                21: 'FTP - Unencrypted file transfer',
                23: 'Telnet - Unencrypted remote access',
                25: 'SMTP - Potential relay abuse',
                3306: 'MySQL - Direct database access',
                5432: 'PostgreSQL - Direct database access',
                6379: 'Redis - Unauthenticated access possible'
            }

            for port, info in listening_ports.items():
                if port in dangerous_ports:
                    vulns.append({
                        'name': f'Insecure Port {port} Open',
                        'severity': 'high',
                        'description': f'{dangerous_ports[port]}. Process: {info["proc"]}',
                        'location': f'{info["laddr"]}:{port}',
                        'cve': f'CVE-2024-{port}',
                        'mitigation': f'Close port {port} using firewall (iptables) or stop process ({info["proc"]})',
                        'impact': 'Unauthorized access or data interception',
                        'category': 'network',
                        'port': port  # Store port for mitigation
                    })
        except Exception as e:
            print(f"Network scan error: {e}")

        return vulns[:3]

    def check_weak_permissions(self):
        """Check for weak file permissions (Real config check)"""
        vulns = []

        try:
            sensitive_files = [
                '/etc/passwd',
                '/etc/shadow',
                '/etc/ssh/sshd_config',
                '/root/.ssh/authorized_keys'
            ]

            for file_path in sensitive_files:
                if os.path.exists(file_path):
                    stat_info = os.stat(file_path)
                    permissions = oct(stat_info.st_mode)[-3:]

                    # Check if world-readable or world-writable
                    if int(permissions[2]) > 0:
                        vulns.append({
                            'name': f'Weak Permissions on {os.path.basename(file_path)}',
                            'severity': 'high',
                            'description': f'File has permissions {permissions} - too permissive',
                            'location': file_path,
                            'cve': 'N/A',
                            'mitigation': f'chmod 600 {file_path}',
                            'impact': 'Unauthorized information disclosure',
                            'category': 'permissions'
                        })
        except Exception as e:
            print(f"Permission scan error: {e}")

        return vulns[:2]

    def check_dns_cache_poisoning(self):
        """Check DNS configuration (Real config check)"""
        vulns = []

        try:
            # Check if DNSSEC is enabled
            resolv_conf = '/etc/resolv.conf'
            if os.path.exists(resolv_conf):
                with open(resolv_conf, 'r') as f:
                    content = f.read()

                if 'dnssec' not in content.lower():
                    vulns.append({
                        'name': 'DNS Cache Poisoning Risk',
                        'severity': 'medium',
                        'description': 'DNSSEC validation not enabled',
                        'location': resolv_conf,
                        'cve': 'CVE-2024-DNS1',
                        'mitigation': 'Enable DNSSEC validation in DNS resolver configuration',
                        'impact': 'Man-in-the-middle attacks via DNS spoofing',
                        'category': 'cache_poisoning'
                    })
        except Exception as e:
            print(f"DNS scan error: {e}")

        return vulns

    def check_weak_crypto(self):
        """Check for weak cryptographic configurations (Real config check)"""
        vulns = []

        # Check SSH configuration
        ssh_config = '/etc/ssh/sshd_config'
        try:
            if os.path.exists(ssh_config):
                with open(ssh_config, 'r') as f:
                    content = f.read()

                if 'PermitRootLogin yes' in content:
                    vulns.append({
                        'name': 'Root Login Permitted via SSH',
                        'severity': 'critical',
                        'description': 'SSH allows direct root login',
                        'location': ssh_config,
                        'cve': 'N/A',
                        'mitigation': 'Set PermitRootLogin to no in sshd_config and restart sshd',
                        'impact': 'Direct root access attack surface',
                        'category': 'authentication',
                        'auth_type': 'root_login'
                    })

                if 'PasswordAuthentication yes' in content:
                    vulns.append({
                        'name': 'Password Authentication Enabled',
                        'severity': 'medium',
                        'description': 'SSH allows password-based authentication',
                        'location': ssh_config,
                        'cve': 'N/A',
                        'mitigation': 'Disable password auth, use key-based authentication only, and restart sshd',
                        'impact': 'Brute force attack vulnerability',
                        'category': 'authentication',
                        'auth_type': 'password_auth'
                    })
        except Exception as e:
            print(f"Crypto scan error: {e}")

        return vulns

    def check_insecure_environment_variables(self):
        """Check for insecure environment variables (Simulated check)"""
        vulns = []

        # --- SIMULATED INSECURE CHECK ---
        simulated_config_path = '/opt/app/config.ini'

        try:
            # Check for weak Flask Secret Key in current environment
            if 'FLASK_SECRET_KEY' in os.environ and len(os.environ['FLASK_SECRET_KEY']) < 16:
                vulns.append({
                    'name': 'Weak/Short FLASK_SECRET_KEY',
                    'severity': 'medium',
                    'description': 'The Flask SECRET_KEY is present and appears to be too short (less than 16 characters), making sessions vulnerable.',
                    'location': 'Application Environment',
                    'cve': 'N/A',
                    'mitigation': 'Use a strong, 32+ character, randomly generated secret key stored securely.',
                    'impact': 'Session hijacking and remote code execution if used improperly.',
                    'category': 'configuration'
                })

            # Add a mock vulnerability
            vulns.append({
                'name': 'Hardcoded AWS Key Found',
                'severity': 'critical',
                'description': 'Simulated detection of "AWS_SECRET_ACCESS_KEY=AKIA...KEY" in config file.',
                'location': simulated_config_path,
                'cve': 'N/A',
                'mitigation': 'Remove hardcoded credentials; use IAM roles or secure secrets manager.',
                'impact': 'Full compromise of cloud resources.',
                'category': 'configuration'
            })

        except Exception as e:
            print(f"Environment variable scan error: {e}")

        return vulns

    def run_full_scan(self):
        """Run all vulnerability scans"""
        all_vulns = []
        scan_functions = [
            self.check_buffer_overflow_vulnerabilities,
            self.check_privilege_escalation,
            self.check_network_vulnerabilities,
            self.check_weak_permissions,
            self.check_dns_cache_poisoning,
            self.check_weak_crypto,
            self.check_insecure_environment_variables
        ]

        total_scans = len(scan_functions)
        for idx, scan_func in enumerate(scan_functions):
            try:
                vulns = scan_func()
                all_vulns.extend(vulns)
                scan_status['progress'] = ((idx + 1) / total_scans) * 100
                time.sleep(0.5)  # Simulate scan time
            except Exception as e:
                print(f"Error in {scan_func.__name__}: {e}")

        return all_vulns


class MitigationEngine:
    """Engine for applying security mitigations using real shell commands."""

    @staticmethod
    def apply_mitigation(vulnerability):
        """Apply mitigation for a specific vulnerability"""
        category = vulnerability.get('category', 'unknown')
        location = vulnerability.get('location', '')

        actions_taken = []

        try:
            if category == 'permissions':
                # REAL ACTION: Change file permissions
                # This will fail unless running as root
                command = ['chmod', '600', location]
                subprocess.run(command, check=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
                actions_taken.append(f"REAL fix: Executed `{' '.join(command)}` on {location}")

            elif category == 'network':
                # REAL ACTION: Drop traffic on the specific port using iptables (IPv4)
                # This will fail unless running as root
                port = vulnerability.get('port')
                if port:
                    command = ['iptables', '-A', 'INPUT', '-p', 'tcp', '--dport', str(port), '-j', 'DROP']
                    subprocess.run(command, check=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
                    actions_taken.append(f"REAL fix: Executed `{' '.join(command)}` to block port {port}")
                else:
                    actions_taken.append("REAL Action failed: Port information missing for network mitigation.")

            elif category == 'authentication':
                # REAL ACTION: Edit SSH config using sed (FIXED SYNTAX)
                # This will fail unless running as root
                auth_type = vulnerability.get('auth_type')

                if auth_type == 'root_login':
                    # Replace PermitRootLogin yes with no, handling commented lines
                    # Using '|' as a delimiter to prevent syntax errors
                    sed_cmd = f"sed -i 's|^PermitRootLogin yes|PermitRootLogin no|; s|^#PermitRootLogin yes|PermitRootLogin no|' {location}"
                    subprocess.run(sed_cmd, shell=True, check=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
                    actions_taken.append(f"REAL fix: Disabled PermitRootLogin in {location}")

                elif auth_type == 'password_auth':
                    # Replace PasswordAuthentication yes with no
                    # Using '|' as a delimiter to prevent syntax errors
                    sed_cmd = f"sed -i 's|^PasswordAuthentication yes|PasswordAuthentication no|; s|^#PasswordAuthentication yes|PasswordAuthentication no|' {location}"
                    subprocess.run(sed_cmd, shell=True, check=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
                    actions_taken.append(f"REAL fix: Disabled PasswordAuthentication in {location}")

                # IMPORTANT: Restart SSH service (Command depends on Linux distro/init system)
                try:
                    subprocess.run(['systemctl', 'restart', 'sshd'], check=True, stdout=subprocess.PIPE,
                                   stderr=subprocess.PIPE)
                    actions_taken.append("REAL Action: Restarted SSH daemon (sshd) for changes to take effect.")
                except subprocess.CalledProcessError:
                    actions_taken.append(
                        "REAL Action: Attempted SSH restart, but service restart command failed (manual restart required).")

            elif category == 'configuration' or category == 'buffer_overflow' or category == 'privilege_escalation' or category == 'cache_poisoning':
                # These remain manual/simulated for safety and complexity.
                actions_taken.append("Security alert logged. Manual review and system patching required.")

            else:
                actions_taken.append("Security alert logged. No automatic action defined for this category.")

            return {
                'success': True,
                'actions': actions_taken,
                'timestamp': datetime.now().isoformat()
            }

        except subprocess.CalledProcessError as e:
            # Handle error if the shell command fails (e.g., permission denied)
            error_output = e.stderr.decode('utf-8').strip() or e.stdout.decode('utf-8').strip()
            return {
                'success': False,
                'error': f"Mitigation command failed. Ensure root privileges are granted. Error: {error_output}",
                'timestamp': datetime.now().isoformat()
            }
        except Exception as e:
            # Handle general Python exceptions
            return {
                'success': False,
                'error': str(e),
                'timestamp': datetime.now().isoformat()
            }


# API Endpoints (These remain unchanged)

@app.route('/api/scan', methods=['POST'])
def start_scan():
    """Start a vulnerability scan"""
    global vulnerabilities_db, scan_status

    if scan_status['scanning']:
        return jsonify({'error': 'Scan already in progress'}), 400

    def run_scan():
        global vulnerabilities_db, system_logs, scan_status

        scan_status['scanning'] = True
        scan_status['progress'] = 0

        add_log('Starting comprehensive vulnerability scan...', 'info')

        scanner = VulnerabilityScanner()
        results = scanner.run_full_scan()

        # Add timestamps and IDs
        for idx, vuln in enumerate(results):
            vuln['id'] = int(time.time() * 1000) + idx
            vuln['detected'] = datetime.now().isoformat()
            vuln['status'] = 'active'

        vulnerabilities_db = results
        scan_status['scanning'] = False
        scan_status['progress'] = 100

        add_log(f'Scan complete. Found {len(results)} vulnerabilities.', 'success')

    # Run scan in background thread
    thread = threading.Thread(target=run_scan)
    thread.daemon = True
    thread.start()

    return jsonify({'message': 'Scan started', 'status': 'running'})


@app.route('/api/vulnerabilities', methods=['GET'])
def get_vulnerabilities():
    """Get all detected vulnerabilities"""
    return jsonify({
        'vulnerabilities': vulnerabilities_db,
        'total': len(vulnerabilities_db),
        'critical': len([v for v in vulnerabilities_db if v['severity'] == 'critical' and v['status'] == 'active']),
        'high': len([v for v in vulnerabilities_db if v['severity'] == 'high' and v['status'] == 'active']),
        'medium': len([v for v in vulnerabilities_db if v['severity'] == 'medium' and v['status'] == 'active']),
        'low': len([v for v in vulnerabilities_db if v['severity'] == 'low' and v['status'] == 'active'])
    })


@app.route('/api/mitigate/<int:vuln_id>', methods=['POST'])
def mitigate_vulnerability(vuln_id):
    """Apply mitigation for a specific vulnerability"""
    global vulnerabilities_db, mitigation_history

    vuln = next((v for v in vulnerabilities_db if v['id'] == vuln_id), None)

    if not vuln:
        return jsonify({'error': 'Vulnerability not found'}), 404

    add_log(f'Applying REAL mitigation for vulnerability ID: {vuln_id}...', 'info')

    # Apply mitigation
    mitigation_result = MitigationEngine.apply_mitigation(vuln)

    if mitigation_result['success']:
        vuln['status'] = 'mitigated'
        vuln['mitigation_applied'] = datetime.now().isoformat()
        mitigation_history.append({
            'vuln_id': vuln_id,
            'timestamp': datetime.now().isoformat(),
            'actions': mitigation_result['actions']
        })
        add_log(f'✓ Vulnerability ID {vuln_id} SUCCESSFULLY REAL-MITIGATED', 'success')

        return jsonify({
            'success': True,
            'message': 'Real mitigation applied',
            'actions': mitigation_result['actions']
        })
    else:
        add_log(
            f'✗ Failed to apply REAL mitigation for vulnerability ID {vuln_id}. Reason: {mitigation_result.get("error", "Unknown error")}',
            'error')
        return jsonify({
            'success': False,
            'error': mitigation_result.get('error', 'Unknown error')
        }), 500


@app.route('/api/metrics', methods=['GET'])
def get_system_metrics():
    """Get real-time system metrics"""
    try:
        cpu_percent = psutil.cpu_percent(interval=1)
        memory = psutil.virtual_memory()
        disk = psutil.disk_usage('/')
        net_io = psutil.net_io_counters()

        return jsonify({
            'cpu_usage': cpu_percent,
            'memory_usage': memory.percent,
            'disk_usage': disk.percent,
            'network_sent': net_io.bytes_sent,
            'network_recv': net_io.bytes_recv,
            'timestamp': datetime.now().isoformat()
        })
    except Exception as e:
        return jsonify({'error': str(e)}), 500


@app.route('/api/logs', methods=['GET'])
def get_logs():
    """Get system logs"""
    return jsonify({'logs': system_logs[-100:]})  # Return last 100 logs


@app.route('/api/scan/status', methods=['GET'])
def get_scan_status():
    """Get current scan status"""
    return jsonify(scan_status)


@app.route('/api/export', methods=['GET'])
def export_report():
    """Export vulnerability report"""
    report = {
        'generated': datetime.now().isoformat(),
        'summary': {
            'total_vulnerabilities': len(vulnerabilities_db),
            'critical': len([v for v in vulnerabilities_db if v['severity'] == 'critical']),
            'high': len([v for v in vulnerabilities_db if v['severity'] == 'high']),
            'medium': len([v for v in vulnerabilities_db if v['severity'] == 'medium']),
            'low': len([v for v in vulnerabilities_db if v['severity'] == 'low']),
            'mitigated': len([v for v in vulnerabilities_db if v['status'] == 'mitigated'])
        },
        'vulnerabilities': vulnerabilities_db,
        'mitigation_history': mitigation_history
    }

    return jsonify(report)


def add_log(message, log_type='info'):
    """Add entry to system logs"""
    global system_logs
    system_logs.append({
        'timestamp': datetime.now().strftime('%H:%M:%S'),
        'message': message,
        'type': log_type
    })


@app.route('/api/health', methods=['GET'])
def health_check():
    """Health check endpoint"""
    return jsonify({
        'status': 'healthy',
        'timestamp': datetime.now().isoformat()
    })


if __name__ == '__main__':
    add_log("Backend Server Initialized. Mitigation is now REAL (requires root/sudo access).", 'info')
    print("=" * 60)
    print("Security Vulnerability Detection Framework")
    print("Backend Server Starting...")
    print("!!! MITIGATION IS REAL - RUN AS ROOT OR USE SUDOERS !!!")
    print("=" * 60)
    print("API Endpoints:")
    print("  POST    /api/scan               - Start vulnerability scan")
    print("  GET     /api/vulnerabilities  - Get detected vulnerabilities")
    print("  POST    /api/mitigate/<id>    - Apply REAL mitigation")
    print("  GET     /api/metrics          - Get system metrics")
    print("  GET     /api/logs             - Get system logs")
    print("  GET     /api/scan/status      - Get scan status")
    print("  GET     /api/export           - Export vulnerability report")
    print("=" * 60)

    # Running on port 5001
    app.run(debug=True, host='0.0.0.0', port=5001)