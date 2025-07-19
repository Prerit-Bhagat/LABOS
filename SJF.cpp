#include <bits/stdc++.h>
using namespace std;

struct process
{
    int pid;
    int arrival = 0; // constraint given for sjf with arrival time=0
    int burst;
};

bool compTasks(process a, process b)
{
    if (a.arrival == b.arrival)
    {
        if (a.burst == b.burst)
            return a.pid < b.pid;
        return a.burst < b.burst;
    }
    return a.arrival < b.arrival;
}
void calcct(process arr[], int n,int ct[])
{
	ct[0]=arr[0].burst;
	for(int i=1;i<n;i++)
	{
        // cout<<bt[i][1]<<endl;
		ct[i]=ct[i-1]+arr[i].burst;
	}
    float avgct=0;
	for(int i=0;i<n;i++)
	{
        avgct+=ct[i];
    }
	cout<<avgct/n<<endl;
}
void sjfnon(process arr[], int n)
{
    sort(arr, arr + n, compTasks);  
    int currtime = 0;
    int ct[n];
	int wt[n];
    int delay;
    int TAT[n];
	calcct(arr,n,ct);  
    float avgTAT = 0;
	float totalwt = 0;
    for (int i = 0; i < n; i++)
    {
        TAT[i]=ct[i]-arr[i].arrival;
		wt[i]=TAT[i]-arr[i].burst;
		avgTAT+=TAT[i];
		totalwt+=wt[i];
    }
    totalwt = (totalwt / n);
    avgTAT = (avgTAT / n);
    cout << "Average Waiting Time: " << totalwt << endl;
    cout << "Average Turnaround Time: " << avgTAT << endl;
    cout << "PID"<< "\t\t"<< "BT"<< "\t\t"<< "CT"<< "\t\t"<< "TAT"<< "\t\t"<< "WT" << endl;
		for (int i = 0; i < n; i++)
		{
			cout<<arr[i].pid<<'\t'<<arr[i].burst<<'\t'<<ct[i]<<'\t'<<TAT[i]<<'\t'<<wt[i]<<endl;
		}
		
}

int main()
{
    cout << "enter number of processes: ";
    int n;
    cin >> n;
    process arr[n];

    cout << "enter process id, burst time (arrival time is same, ie 0): \n";
    for (int i = 0; i < n; i++)
        cin >> arr[i].pid >> arr[i].burst;

    sjfnon(arr, n);

    return 0;
}