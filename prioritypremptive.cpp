#include <iostream>
#include <queue>

using namespace std;

struct Process {
    int id;
    int priority;
    int burst_time;
    int arrival_time;
};

struct ComparePriority {
    bool operator()(const Process& p1, const Process& p2) {
        return p1.priority > p2.priority;
    }
};

void prioritySchedulingPreemptive(vector<Process>& processes) {
    priority_queue<Process, vector<Process>, ComparePriority> pq;
    int currentTime = 0;
    int completed = 0;

    while (completed < processes.size()) {
        for (int i = 0; i < processes.size(); ++i) {
            if (processes[i].arrival_time <= currentTime && processes[i].burst_time > 0) {
                pq.push(processes[i]);
            }
        }

        if (!pq.empty()) {
            Process current = pq.top();
            pq.pop();

            cout << "Executing process " << current.id << " at time " << currentTime << endl;
            current.burst_time--;
            currentTime++;

            if (current.burst_time == 0) {
                completed++;
            } else {
                pq.push(current);
            }
        } else {
            currentTime++;
        }
    }
}


int main() {
    vector<Process> processes = {
        {1, 2, 5, 0},
        {2, 1, 3, 2},
        {3, 4, 7, 4},
        {4, 3, 2, 6}
    };

    prioritySchedulingPreemptive(processes);
	return 0;
}