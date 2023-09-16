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
public:
    int maxValue(vector<vector<int>>& grid) {
        int row = grid.size();
        if(row == 0) return 0;
        int col = grid[0].size();

        for(int i = 0; i < row; i ++) {
            for(int j = 0; j < col; j ++) {
                int from_up = (i > 0) ? grid[i - 1][j] : 0;
                int from_left = (j > 0) ? grid[i][j - 1] : 0;
                grid[i][j] = max(from_up + grid[i][j], from_left + grid[i][j]);
            }
        }
        return grid[row - 1][col - 1];
    }
};

int main() {
    
    return 0;
}
