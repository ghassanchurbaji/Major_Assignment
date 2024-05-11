#include <iostream>
#include <vector>

using namespace std;

int numberSequence(int m, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int j = 1; j <= m; ++j) {
        dp[1][j] = 1;
    }

    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            for (int k = 1; k <= j / 2; ++k) {
                dp[i][j] += dp[i-1][k];
            }
        }
    }

    int totalSequences = 0;
    for (int j = 1; j <= m; ++j) {
        totalSequences += dp[n][j];
    }

    return totalSequences;
}

int main() {
    // Example 1
    int m1 = 10, n1 = 4;
    cout << "Example 1 Total special sequences for m = 10, n = 4: " << numberSequence(m1, n1) << endl;

    // Example 2
    int m2 = 5, n2 = 2;
    cout << "Example 2 Total special sequences for m = 5, n = 2: " << numberSequence(m2, n2) << endl;

    return 0;
}
