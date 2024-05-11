#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Pair {
    int first, second;
};

bool compare(Pair a, Pair b) {
    return a.second < b.second;
}

int maxChainLen(vector<Pair>& pairs, int N) {
    sort(pairs.begin(), pairs.end(), compare);
    int count = 1;  
    int end = pairs[0].second;  

    for (int i = 1; i < N; i++) {
        if (pairs[i].first > end) {
            count++;  
            end = pairs[i].second;  
        }
    }

    return count;
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
