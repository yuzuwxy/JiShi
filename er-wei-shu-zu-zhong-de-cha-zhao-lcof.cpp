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
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        if(row == 0) return false;
        int col = matrix[0].size();
        int i = row - 1, j = 0;
        while(i >= 0 && i < row && j >= 0 && j < col) {
            if(matrix[i][j] < target) j ++;
            else if(matrix[i][j] > target) i --;
            else if(matrix[i][j] == target) break;
        }
        if(i >= 0 && i < row && j >= 0 && j < col)
            return matrix[i][j] == target;
        return false;
    }
};

int main() {
    
    return 0;
}
