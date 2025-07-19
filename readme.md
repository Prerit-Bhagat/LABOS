# OS Scheduling Algorithms & Deadlock Detection

This project contains C++ implementations of core Operating System (OS) concepts including:

- **CPU Scheduling Algorithms**
  - FCFS (First-Come, First-Served)
  - SJF (Shortest Job First)
  - Round Robin
  - Priority Scheduling (Non-Preemptive)
  - Priority Scheduling (Preemptive)
- **Deadlock**
  - Detection and/or Avoidance (e.g., Banker's Algorithm)

---

## 📁 Files

| File Name                 | Description                               |
| ------------------------- | ----------------------------------------- | ------------------------------------ | --- |
| `fcfs.cpp`                | FCFS Scheduling Algorithm                 |
| `sjf.cpp`                 | SJF Scheduling Algorithm                  |
| `roundrobin.cpp`          | Round Robin Scheduling Algorithm          |
| `priority.cpp`            | Priority Scheduling (Non-Preemptive)      |
| `priority_preemptive.cpp` | Priority Scheduling (Preemptive)          |
| `deadlock.cpp`            | Deadlock Detection or Avoidance Algorithm |
| <!--                      | `.gitignore`                              | Git ignore rules                     | --> |
| <!--                      | `Untitled3.cpp`                           | (Optional) Temporary or scratch file | --> |

---

## 🧠 Algorithm Overview

### 🕒 FCFS (First-Come, First-Served)

- Non-preemptive.
- Jobs are executed in the order they arrive.
- Simple but can lead to long waiting times.

### ⏱️ SJF (Shortest Job First)

- Non-preemptive.
- Executes the shortest process first.
- Reduces average waiting time but can starve longer processes.

### 🔁 Round Robin

- Preemptive scheduling with a fixed time quantum.
- Each process gets equal time in a cyclic order.
- Good for time-sharing systems.

### ⚡ Priority Scheduling

#### ➤ Non-Preemptive:

- Higher-priority processes are executed first.
- If two processes have the same priority, FCFS is used.

#### ➤ Preemptive:

- A higher-priority process can preempt a currently running lower-priority process.
- Fairer in some cases, but more complex.

### ⚠️ Deadlock Detection / Avoidance

- Detects if a system is in a **deadlock state**.
- May use:
  <!-- - **Wait-for Graph** -->
  - **Banker's Algorithm**
- Can print:
  - Safe sequence (if any)
  - Detected deadlock processes

---

## 🧪 Sample Output
