#include <iostream>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>
#include<stack>

#define MAXN (int)1e5
#define ll long long

using namespace std;

class Solution {
private:
    int len_row, len_col, len_word;
    bool ans = false;
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

public:
    // 当前已经搜索到的行和列
    // 下一个需要匹配的word字符下标
    void dfs(int row, int col, int cur, vector<vector<bool>>& vis, vector<vector<char>>& board, string word) {
        if(cur == len_word) {
            ans = true;
            return;
        }

        for(int i = 0; i < 4; i ++) {
            int nxt_r = row + dir[i][0], nxt_c = col + dir[i][1];
            if(nxt_r >= 0 && nxt_r < len_row && nxt_c >= 0 && nxt_c < len_col) {
                if(vis[nxt_r][nxt_c] == false && board[nxt_r][nxt_c] == word[cur]) {
                    vis[nxt_r][nxt_c] = true;
                    dfs(nxt_r, nxt_c, cur + 1, vis, board, word);
                    vis[nxt_r][nxt_c] = false;
                }
            }
        }
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        len_row = board.size();
        if(len_row == 0) return word == "";
        len_col = board[0].size();
        len_word = word.size();
        if(len_word == 0) return true;
        for(int i = 0; i < len_row; i ++) {
            for(int j = 0; j < len_col; j ++) {
                if(board[i][j] == word[0]) {
                    vector<vector<bool>> vis(len_row, vector<bool>(len_col, false));
                    vis[i][j] = true;
                    dfs(i, j, 1, vis, board, word);
                    vis[i][j] = false;
                }
            }
        }
        return ans;
    }
};

int main() {
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string word = "ABCCED";
    Solution s;
    s.exist(board, word);
    return 0;
}
