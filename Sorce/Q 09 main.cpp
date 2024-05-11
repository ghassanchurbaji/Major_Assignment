#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

struct TrieNode {
    TrieNode* child[26] = {};
    bool isEndOfWord = false;

    ~TrieNode() {
        for (int i = 0; i < 26; i++) {
            if (child[i]) delete child[i];
        }
    }
};

class Solution {
public:
    void insertTrie(TrieNode* root, const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            int index = tolower(c) - 'a';
            if (!node->child[index]) {
                node->child[index] = new TrieNode();
            }
            node = node->child[index];
        }
        node->isEndOfWord = true;
    }

    void findWords(vector<vector<char>>& board, int x, int y, TrieNode* node, vector<string>& result, string& path, vector<vector<bool>>& visited) {
        if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size() || visited[x][y])
            return;

        char c = board[x][y];
        node = node->child[tolower(c) - 'a'];
        if (!node) return;

        visited[x][y] = true;
        path.push_back(c);

        if (node->isEndOfWord) {
            if (result.empty() || result.back() != path)  // to avoid duplicates
                result.push_back(path);
        }

        static int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
        static int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};

        for (int dir = 0; dir < 8; ++dir) {
            findWords(board, x + dx[dir], y + dy[dir], node, result, path, visited);
        }

        visited[x][y] = false;
        path.pop_back();
    }

    vector<string> wordBoggle(vector<vector<char>>& board, vector<string>& dictionary) {
        TrieNode* root = new TrieNode();
        for (const string& word : dictionary) {
            insertTrie(root, word);
        }

        vector<string> result;
        string path;
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                findWords(board, i, j, root, result, path, visited);
            }
        }

        delete root;
        return result;
    }
};

int main() {
    // Example usage:
    vector<vector<char>> board1 = {{'C','A','P'}, {'A','N','D'}, {'T','I','E'}};
    vector<string> dictionary1 = {"CAT"};
    Solution solution;
    vector<string> result1 = solution.wordBoggle(board1, dictionary1);
    for (const string& word : result1) {
        cout << word << endl;
    }

    vector<vector<char>> board2 = {{'G','I','Z'}, {'U','E','K'}, {'Q','S','E'}};
    vector<string> dictionary2 = {"GEEKS", "FOR", "QUIZ", "GO"};
    vector<string> result2 = solution.wordBoggle(board2, dictionary2);
    for (const string& word : result2) {
        cout << word << " ";
    }
    cout << endl;

    return 0;
}
