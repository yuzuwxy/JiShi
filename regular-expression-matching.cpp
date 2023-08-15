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
    bool isMatch(string s, string p) {
        int len_s = s.size(), len_p = p.size();
        
        bool dp[25][25] = {0};      // dp[i][j]表示s(0, i-1)和p(0,j-1)可以匹配

        // 空串和空串可以匹配
        dp[0][0] = true;
        // s为空串，模式串不是空串
        for(int i = 1; i <= len_p; i ++) 
            if(p[i - 1] == '*') dp[0][i] = dp[0][i - 2];
        

        for(int i = 1; i <= len_s; i ++) {
            for(int j = 1; j <= len_p; j ++) {
                if(s[i - 1] == p[j - 1] || p[j - 1] == '.') {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else {
                    if(p[j - 1] == '*') {
                        if(s[i - 1] == p[j - 2] || p[j -2] == '.') {
                            dp[i][j] = dp[i][j - 2] || dp[i - 1][j - 2] || dp[i - 1][j];
                            // cout << "branch2: " << endl;
                        }
                        else {
                            dp[i][j] = dp[i][j - 2];
                        }
                    }
                    else {
                        dp[i][j] = false;
                    }
                }
            }
        }
        return dp[len_s][len_p];
    }
};

int main() {
    Solution s;
    cout << s.isMatch("ab", ".*") << endl;
    return 0;
}
