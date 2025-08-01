#include <iostream>
using namespace std;

// Returns the index of the process with the minimum burst time
int minimumPT(int PT[], int n)
{
    int min = 10000;
    int min_index = 0;
    for (int i = 0; i < n; i++)
    {
        if (PT[i] < min && PT[i]>=0)
        {
            min = PT[i];
            min_index = i;
        }
    }
    return min_index;
}

// Returns true if all the processes have executed else returns false
bool check(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            return false;
        }
    }
    return true;
}

// Driver Main
int main()
{
    int n = 3;
    int process[] = {1, 2, 3};
    int arrival_time[] = {0,3,0};
    int burst_time[] = {10,5,8};
    int burst_time_original[] = {10,5,8};
	int PT[]={2,0,1};
    int is_complete[] = {0, 0, 0}; // To keep track of the completed processes

    int tat[] = {0, 0, 0};
    int waiting_time[] = {0, 0, 0};
    int exit_time[] = {0, 0, 0};

    // Sorting all the processes according to the arrival times
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arrival_time[j] > arrival_time[j + 1])
            {
                swap(process[j], process[j + 1]);
                swap(arrival_time[j], arrival_time[j + 1]);
                swap(burst_time[j], burst_time[j + 1]);
                swap(burst_time_original[j], burst_time_original[j + 1]);
                swap(PT[j],PT[j+1]);
            }
        }
    }

    // Time variable to keep track of the time
    int time = arrival_time[0];
    while (!check(is_complete, n))
    {
        int j = 0;
        // Checking how many process have arrival time <= current time and then setting the j pointer accordingly
        for (int i = 0; i < n; i++)
        {
            if (arrival_time[i] <= time)
            {
                j++;
            }
        }

        // Running the task with the minimum BT
        int running = minimumPT(PT, j);
//		cout<<running<<endl;
        // Updating the time variable
        time = time + burst_time[running];
	
        burst_time[running] = 0;
        PT[running]=-1;
        is_complete[running] = 1;
//		cout<<"H\n";
        exit_time[running] = time;
    }

    // Calculating the TurnAroundTime and Waiting Time for (int i = 0; i < n; i++)
    for (int i = 0; i < n; i++)
    {
        tat[i] = exit_time[i] - arrival_time[i];
        waiting_time[i] = tat[i] - burst_time_original[i];
    }

    // Printing all the data
    cout << "P"
         << "\t"
         << "AT"
         << "\t"
         << "BT"
         << "\t"
         << "WT"
         << "\t"
         << "TAT"
         << "\t"
         << "ExitT" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << process[i] << "\t" << arrival_time[i] << "\t" << burst_time_original[i] << "\t" << waiting_time[i] << "\t" << tat[i] << "\t" << exit_time[i] << endl;
    }
    return 0;
}
