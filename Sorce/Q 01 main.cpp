#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxMeetings(int start[], int end[], int n) {
    vector<pair<int, int>> meetings;
    for (int i = 0; i < n; i++) {
        meetings.push_back({end[i], start[i]});
    }
    sort(meetings.begin(), meetings.end());
    int count = 0;
    int last_end_time = 0;

    for (int i = 0; i < n; i++) {
        if (meetings[i].second > last_end_time) {
            last_end_time = meetings[i].first;
            count++;
        }
    }
    return count;
}

int main() {
    // Example 1
    int N = 6;
    int start[] = {1, 3, 0, 5, 8, 5};
    int end[] = {2, 4, 6, 7, 9, 9};
    cout << "Maximum number of meetings for Example 1: " << maxMeetings(start, end, N) << endl;

    // Example 2
    int N2 = 3;
    int start2[] = {10, 12, 20};
    int end2[] = {20, 25, 30};
    cout << "Maximum number of meetings for Example 2: " << maxMeetings(start2, end2, N2) << endl;

    return 0;
}
