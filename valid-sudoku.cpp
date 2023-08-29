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

#define MAXN (int)1e5
#define ll long long

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool ans = true;
        // 判断每行和每列
        for(int i = 0; i < 9; i ++) {
            bool row_vis[10] = {false};
            bool col_vis[10] = {false};
            if(!ans) break;
            for(int j = 0; j < 9; j ++) {
                if(board[i][j] != '.') {    // 行
                    if(row_vis[board[i][j] - '0']) {
                        ans = false;
                        break;
                    }
                    else row_vis[board[i][j] - '0'] = true;

                }
                if(board[j][i] != '.') {    // 列
                    if(col_vis[board[j][i] - '0']) {
                        ans = false; 
                        break;
                    }
                    else col_vis[board[j][i] - '0'] = true; 
                }
            }
        }

        // 判断每个3 * 3 的方格
        for(int i = 0; i < 9; i += 3) {
            if(!ans) break;
            for(int j = 0; j < 9; j += 3) {     // 每个3*3的左上角
                if(!ans) break;
                bool vis[10] = {false};
                for(int u = i; u < i + 3; u ++) {
                    if(!ans) break;
                    for(int v = j; v < j + 3; v ++) {
                        if(board[u][v] != '.') {
                            if(vis[board[u][v] - '0']) {
                                ans = false;
                                break;
                            }
                            else vis[board[u][v] - '0'] = true;
                        }
                    }
                }
            }
        }

        return ans;
    }
};

int main() {
    
    return 0;
}
