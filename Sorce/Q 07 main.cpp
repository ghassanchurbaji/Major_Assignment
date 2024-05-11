#include <iostream>
#include <vector>

using namespace std;

bool isSafe(int node, vector<vector<int>>& graph, vector<int>& colors, int col) {
    for (int i = 0; i < graph.size(); i++) {
        if (graph[node][i] && colors[i] == col) {
            return false; 
        }
    }
    return true;
}

bool graphColoringUtil(vector<vector<int>>& graph, int m, vector<int>& colors, int v) {
    if (v == graph.size()) {
        return true; 
    }

    for (int c = 1; c <= m; c++) { 
        if (isSafe(v, graph, colors, c)) {
            colors[v] = c; 
            if (graphColoringUtil(graph, m, colors, v + 1)) {
                return true;
            }
            colors[v] = 0; 
        }
    }

    return false; 
}

bool graphColoring(vector<vector<int>>& graph, int m, int n) {
    vector<int> colors(n, 0); 
    return graphColoringUtil(graph, m, colors, 0);
}

int main() {
    // Example 1
    int N1 = 4, M1 = 3;
    vector<vector<int>> graph1 = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };
    cout << "Example 1 Output: " << (graphColoring(graph1, M1, N1) ? 1 : 0) << endl;

    // Example 2
    int N2 = 3, M2 = 2;
    vector<vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}
    };
    cout << "Example 2 Output: " << (graphColoring(graph2, M2, N2) ? 1 : 0) << endl;

    return 0;
}
