#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sumOfVector(const vector<int>& vec) {
    int total = 0;
    for (int num : vec) {
        total += num;
    }
    return total;
}

bool isFeasible(const vector<int>& books, int M, int maxPages) {
    int count = 1;
    int sumAllocated = 0;

    for (int pages : books) {
        if (sumAllocated + pages > maxPages) {
            count++;
            sumAllocated = pages;
            if (count > M || pages > maxPages) {
                return false;
            }
        } else {
            sumAllocated += pages;
        }
    }
    return true;
}

int findPages(const vector<int>& books, int N, int M) {
    if (M > N) return -1;

    int low = *max_element(books.begin(), books.end());
    int high = sumOfVector(books);

    while (low < high) {
        int mid = (low + high) / 2;
        if (isFeasible(books, M, mid)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    return low;
}

int main() {
    vector<int> books1 = {12, 34, 67, 90};
    int N1 = 4, M1 = 2;
    cout << "Minimum maximum pages (Example 1): " << findPages(books1, N1, M1) << endl;

    vector<int> books2 = {15, 17, 20};
    int N2 = 3, M2 = 2;
    cout << "Minimum maximum pages (Example 2): " << findPages(books2, N2, M2) << endl;

    return 0;
}
