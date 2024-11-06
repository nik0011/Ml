#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Job structure to store job details
struct Job {
    char id;      // Job ID
    int deadline; // Deadline of the job
    int profit;   // Profit from the job
};

// Comparator function to sort jobs by profit in descending order
bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

// Function to print the job sequence and calculate total profit
void printJobSequence(vector<Job> &jobs) {
    // Step 1: Sort jobs by profit in descending order
    sort(jobs.begin(), jobs.end(), compare);

    int n = jobs.size();

    // Step 2: Find the maximum deadline to know the maximum slot we have
    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        if (jobs[i].deadline > maxDeadline) {
            maxDeadline = jobs[i].deadline;
        }
    }

    // Step 3: Initialize result array for job sequence and a slot array to track free time slots
    vector<char> result(maxDeadline, 'X'); // 'X' indicates empty slot
    vector<bool> slot(maxDeadline, false); // false indicates slot is free

    // Step 4: Try to schedule each job in a slot within its deadline
    for (int i = 0; i < n; i++) {
        // Start from the last possible slot for this job (jobs[i].deadline - 1)
        for (int j = min(maxDeadline, jobs[i].deadline) - 1; j >= 0; j--) {
            if (!slot[j]) { // If slot is free
                result[j] = jobs[i].id; // Place job in this slot
                slot[j] = true; // Mark this slot as occupied
                break;
            }
        }
    }

    // Step 5: Print the job sequence and calculate total profit
    int totalProfit = 0;
    cout << "Job Sequence: ";
    for (int i = 0; i < maxDeadline; i++) {
        if (result[i] != 'X') {
            cout << result[i] << " ";
            // Add the profit of the scheduled job to total profit
            for (Job job : jobs) {
                if (job.id == result[i]) {
                    totalProfit += job.profit;
                    break;
                }
            }
        }
    }
    cout << endl;
    cout << "Total Profit: " << totalProfit << endl;
}

int main() {
    vector<Job> jobs = {
        {'a', 2, 100},
        {'b', 1, 19},
        {'c', 2, 27},
        {'d', 1, 25},
        {'e', 3, 15}
    };

    cout << "Job Sequencing with Deadlines:" << endl;
    printJobSequence(jobs);
    return 0;
}
