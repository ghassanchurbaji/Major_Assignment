#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Pair {
    int first, second;
};

bool compare(Pair a, Pair b) {
    return a.first < b.first;
}

int maxChainLen(vector<Pair>& pairs, int N) {
    sort(pairs.begin(), pairs.end(), compare);  

    vector<int> dp(N, 1);  

    // Fill DP array
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (pairs[j].second < pairs[i].first && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;  
            }
        }
    }

    return *max_element(dp.begin(), dp.end());
}

int main() {
    // Example 1
    vector<Pair> pairs1 = {{5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90}};
    cout << "Maximum chain length for Example 1: " << maxChainLen(pairs1, 5) << endl;

    // Example 2
    vector<Pair> pairs2 = {{5, 10}, {1, 11}};
    cout << "Maximum chain length for Example 2: " << maxChainLen(pairs2, 2) << endl;

    return 0;
}
