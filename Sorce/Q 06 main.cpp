#include <iostream>
#include <vector>
#include <string>

using namespace std;

void searchPaths(vector<vector<int>>& maze, int x, int y, string& path, vector<string>& paths, vector<vector<bool>>& visited, int N) {
    if (x == N - 1 && y == N - 1) {
        paths.push_back(path);
        return;
    }

    visited[x][y] = true;

    if (x + 1 < N && maze[x + 1][y] == 1 && !visited[x + 1][y]) {
        path.push_back('D');
        searchPaths(maze, x + 1, y, path, paths, visited, N);
        path.pop_back(); 
    }

    if (y + 1 < N && maze[x][y + 1] == 1 && !visited[x][y + 1]) {
        path.push_back('R');
        searchPaths(maze, x, y + 1, path, paths, visited, N);
        path.pop_back(); 
    }

    if (x - 1 >= 0 && maze[x - 1][y] == 1 && !visited[x - 1][y]) {
        path.push_back('U');
        searchPaths(maze, x - 1, y, path, paths, visited, N);
        path.pop_back(); 
    }

    if (y - 1 >= 0 && maze[x][y - 1] == 1 && !visited[x][y - 1]) {
        path.push_back('L');
        searchPaths(maze, x, y - 1, path, paths, visited, N);
        path.pop_back(); 
    }

    visited[x][y] = false;
}

vector<string> printPath(int N, vector<vector<int>>& m) {
    vector<string> paths;
    if (m[0][0] == 0 || m[N-1][N-1] == 0) return paths; 

    string path;
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    searchPaths(m, 0, 0, path, paths, visited, N);

    return paths;
}

int main() {
    // Example 1
    vector<vector<int>> maze1 = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };
    vector<string> result1 = printPath(4, maze1);
    if (result1.empty()) {
        cout << "-1" << endl;
    } else {
        for (string s : result1) {
            cout << s << " ";
        }
        cout << endl;
    }

    // Example 2
    vector<vector<int>> maze2 = {
        {1, 0},
        {1, 0}
    };
    vector<string> result2 = printPath(2, maze2);
    if (result2.empty()) {
        cout << "-1" << endl;
    } else {
        for (string s : result2) {
            cout << s << " ";
        }
        cout << endl;
    }

    return 0;
}
