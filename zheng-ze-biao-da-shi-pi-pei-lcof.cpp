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
    bool isMatch(string s, string p) {
        int s_len = s.size();
        int p_len = p.size();

        vector<vector<bool>> dp(s_len + 1, vector<bool>(p_len + 1, false));
        // 0表示空串
        dp[0][0] = true;
        for(int i = 2; i < p_len; i ++) 
            if(p[i] == '*') dp[0][i] = dp[0][i - 2];
        
        for(int i = 1; i <= s_len; i ++) {
            for(int j = 1; j <= p_len; j ++) {
                if(s[i - 1] == p[j - 1] || p[j - 1] == '.')
                    dp[i][j] = dp[i - 1][j - 1];
                else {
                    if(p[j - 1] == '*') {
                        if(p[j - 2] == '.' || s[i - 1] == p[j - 2])
                            dp[i][j] = dp[i][j - 2] || dp[i - 1][j];
                        else dp[i][j] = dp[i][j - 2];
                    }
                    else dp[i][j] = false;
                }
            }
        }
        return dp[s_len][p_len];
    }
};

int main() {
    
    return 0;
}
