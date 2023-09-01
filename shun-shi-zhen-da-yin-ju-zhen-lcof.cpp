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
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int len_row = matrix.size();
        if(len_row == 0) return ans;
        int len_col = matrix[0].size();

        int i = 0, j = 0;
        int circle = 0, count = len_col * len_row;

        while(count --) {
            ans.push_back(matrix[i][j]);
            int border_up = circle, border_down = len_row - circle - 1;
            int border_left = circle, border_right = len_col - circle - 1;
            if(i == border_up) {
                if(j < border_right) j ++;
                else i ++;
            }
            else if(j == border_right) {
                if(i < border_down) i ++;
                else j --;
            }
            else if(i == border_down) {
                if(j > circle) j --;
                else i --;
            }
            else if(j == border_left) {
                if(i > border_up + 1) i --;
                else {
                    circle ++;       // 下一圈
                    j ++;
                }
            }
        }
        return ans;
    }
};

int main() {
    
    return 0;
}
