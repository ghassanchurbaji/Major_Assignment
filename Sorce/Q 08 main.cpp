#include <iostream>
#include <vector>
#include <string>

using namespace std;

void backtrack(vector<string>& result, string& s, int start, int partNum, string currentIP) {
    int n = s.length();
    if (partNum == 4 && start == n) {
        currentIP.pop_back();  
        result.push_back(currentIP);
        return;
    }

    if (partNum == 4 || start == n) return;

    for (int len = 1; len <= 3 && start + len <= n; ++len) {
        string segment = s.substr(start, len);
        int val = stoi(segment);

        if (val > 255 || (len > 1 && s[start] == '0')) continue;

        backtrack(result, s, start + len, partNum + 1, currentIP + segment + ".");
    }
}

vector<string> genIp(string s) {
    vector<string> result;
    if (s.length() < 4 || s.length() > 12) return result;  // Quick check

    string currentIP;
    backtrack(result, s, 0, 0, currentIP);
    return result;
}

int main() {
    // Example 1
    string S1 = "1111";
    vector<string> output1 = genIp(S1);
    for (const string& ip : output1) {
        cout << ip << endl;
    }

    // Example 2
    string S2 = "55";
    vector<string> output2 = genIp(S2);
    if (output2.empty()) {
        cout << "-1" << endl;
    }

    return 0;
}
