#include <iostream>
#include <vector>
#include <algorithm>
#include <climits> 

using namespace std;

int kthElement(int arr1[], int arr2[], int n, int m, int k) {
    if (n > m) return kthElement(arr2, arr1, m, n, k);
    
    int low = max(0, k - m), high = min(k, n);
    
    while (low <= high) {
        int cut1 = (low + high) >> 1;
        int cut2 = k - cut1;
        
        int left1 = cut1 == 0 ? INT_MIN : arr1[cut1 - 1];
        int left2 = cut2 == 0 ? INT_MIN : arr2[cut2 - 1];
        
        int right1 = cut1 == n ? INT_MAX : arr1[cut1];
        int right2 = cut2 == m ? INT_MAX : arr2[cut2];
        
        if (left1 <= right2 && left2 <= right1) {
            return max(left1, left2);
        } else if (left1 > right2) {
            high = cut1 - 1;
        } else {
            low = cut1 + 1;
        }
    }
    
    return 1; 
}

int main() {
    // Example 1
    int arr1[] = {2, 3, 6, 7, 9};
    int arr2[] = {1, 4, 8, 10};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);
    int k = 5;
    cout << "Example 1 Output: " << kthElement(arr1, arr2, n, m, k) << endl;

    // Example 2
    int arr1b[] = {100, 112, 256, 349, 770};
    int arr2b[] = {72, 86, 113, 119, 265, 445, 892};
    n = sizeof(arr1b) / sizeof(arr1b[0]);
    m = sizeof(arr2b) / sizeof(arr2b[0]);
    k = 7;
    cout << "Example 2 Output: " << kthElement(arr1b, arr2b, n, m, k) << endl;

    return 0;
}
