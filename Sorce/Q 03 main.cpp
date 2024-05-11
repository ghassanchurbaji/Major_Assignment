#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Job {
    int id, deadline, profit;
};

// Comparison function to sort jobs based on their deadlines
bool compare(Job a, Job b) {
    return a.deadline < b.deadline;
}

// Dynamic Programming based function to find the maximum profit
int JobScheduling(vector<Job>& jobs, int N) {
    sort(jobs.begin(), jobs.end(), compare);
    vector<int> dp(N);
    dp[0] = jobs[0].profit;

    for (int i = 1; i < N; i++) {
        int inclProfit = jobs[i].profit;
        int l = -1;
        for (int j = i - 1; j >= 0; j--) {
            if (jobs[j].deadline <= jobs[i].deadline - 1) {
                l = j;
                break;
            }
        }
        if (l != -1) inclProfit += dp[l];
        dp[i] = max(dp[i - 1], inclProfit);
    }

    return dp[N - 1];
}

int main() {
    vector<Job> jobs1 = {{1, 4, 20}, {2, 1, 10}, {3, 1, 40}, {4, 1, 30}};
    vector<Job> jobs2 = {{1, 2, 100}, {2, 1, 19}, {3, 2, 27}, {4, 1, 25}, {5, 1, 15}};

    cout << "Maximum profit for Example 1: " << JobScheduling(jobs1, 4) << endl;
    cout << "Maximum profit for Example 2: " << JobScheduling(jobs2, 5) << endl;

    return 0;
}
