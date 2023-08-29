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
    int longestValidParentheses(string s) {
        int ans = 0;
        int len = s.size();

        int dp[3 * 10000 + 7] = {0};    // dp[i]表示以其结尾的最长子串的长度

        for(int i = 1; i < len; i ++) {
            if(s[i] == ')') {
                if(s[i - 1] == ')') {
                    if(i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(')
                        dp[i] = dp[i - 1] 
                                + ((i - 1 - dp[i - 1] - 1 >= 0) ? dp[i - 1 - dp[i - 1] - 1] : 0)
                                + 2;
                }
                else if(s[i - 1] == '(')
                    dp[i] = (((i - 2) >= 0) ? dp[i - 2] : 0) + 2;
                ans = max(ans, dp[i]);
            }
            // 可以实现括号匹配的子串是不可能以左括号结尾的
        }
        return ans;
    }
};

int main() {
    
    return 0;
}
