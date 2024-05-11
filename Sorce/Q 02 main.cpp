#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Job {
    int id, deadline, profit;
};

bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

vector<int> JobScheduling(vector<Job>& jobs, int N) {
    sort(jobs.begin(), jobs.end(), compare); 

    vector<bool> slot(N, false); 
    int maxProfit = 0;
    int countJobs = 0;

    for (int i = 0; i < N; i++) {
        
        for (int j = min(jobs[i].deadline, N) - 1; j >= 0; j--) {
            if (!slot[j]) { 
                slot[j] = true; 
                maxProfit += jobs[i].profit; 
                countJobs++;
                break;
            }
        }
    }

    return {countJobs, maxProfit}; 
}

int main() {
    // Example 1
    vector<Job> jobs1 = {{1, 4, 20}, {2, 1, 10}, {3, 1, 40}, {4, 1, 30}};
    vector<int> result1 = JobScheduling(jobs1, 4);
    cout << "Example 1: " << result1[0] << " jobs done with maximum profit of " << result1[1] << endl;

    // Example 2
    vector<Job> jobs2 = {{1, 2, 100}, {2, 1, 19}, {3, 2, 27}, {4, 1, 25}, {5, 1, 15}};
    vector<int> result2 = JobScheduling(jobs2, 5);
    cout << "Example 2: " << result2[0] << " jobs done with maximum profit of " << result2[1] << endl;

    return 0;
}
