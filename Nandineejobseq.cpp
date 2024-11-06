#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Job {
    int id;       // Job ID
    int deadline; // Job deadline
    int profit;   // Profit if job is completed before or on the deadline

    // Constructor
    Job(int i, int d, int p) : id(i), deadline(d), profit(p) {}
};

// Function to sort jobs in descending order of profit
bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

// Function to schedule jobs to maximize profit
int jobScheduling(vector<Job>& jobs) {
    // Sort jobs in descending order of profit
    sort(jobs.begin(), jobs.end(), compare);

    int maxDeadline = 0;
    // Find the maximum deadline
    for (int i = 0; i < jobs.size(); i++) {
        maxDeadline = max(maxDeadline, jobs[i].deadline);
    }

    // Create a time slot array to keep track of free time slots
    vector<int> schedule(maxDeadline + 1, -1); // -1 indicates a free slot

    int totalProfit = 0;
    // Loop over jobs and schedule them
    for (int i = 0; i < jobs.size(); i++) {
        // Find a free slot for this job, starting from its deadline
        for (int j = jobs[i].deadline; j > 0; j--) {
            if (schedule[j] == -1) {
                schedule[j] = jobs[i].id; // Schedule job at this slot
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    return totalProfit;
}

int main() {
    vector<Job> jobs = {
        {1, 4, 20},
        {2, 1, 10},
        {3, 1, 40},
        {4, 1, 30}
    };

    int maxProfit = jobScheduling(jobs);
    cout << "Maximum profit: " << maxProfit << endl;

    return 0;
}
