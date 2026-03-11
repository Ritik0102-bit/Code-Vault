import time
import random
from flask import Flask, jsonify
from flask_cors import CORS

app = Flask(__name__)
CORS(app)

# --- ATTACK DATA ---
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

MAX_THREAT_LEVEL = 100

def calculate_threat_level(step, total_steps, severity):
    base_level = (step / total_steps) * 70
    bonus = 0
    if severity == "INFO": bonus = random.randint(0, 5)
    elif severity == "WARNING": bonus = random.randint(5, 15)
    elif severity == "ERROR": bonus = random.randint(15, 25)
    elif severity == "CRITICAL": bonus = random.randint(25, 30)
    
    return min(int(base_level + bonus), MAX_THREAT_LEVEL)

@app.route('/api/simulation/<attack_type>')
def run_simulation(attack_type):
    if attack_type not in ATTACK_DATA:
        return jsonify({"error": "Unknown attack"}), 404
        
    data = ATTACK_DATA[attack_type]
    logs = data["logs"]
    total = len(logs)
    
    sequence = []
    for i, (severity, msg) in enumerate(logs):
        threat = calculate_threat_level(i+1, total, severity)
        sequence.append({
            "severity": severity,
            "message": msg,
            "threat_level": threat
        })
        
    return jsonify({
        "sequence": sequence,
        "verdict": data["verdict"],
        "prevention": data["prevention"]
    })

if __name__ == '__main__':
    print("⚡ CYBERPUNK BACKEND ONLINE ⚡")
    app.run(port=5000, debug=True)