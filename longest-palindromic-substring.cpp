#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();

        // 表示下标i-j的字符串是否为回文串
        bool dp[1003][1003];
        for(int i = 0; i < len; i ++)
            dp[i][i] = true;
        int ans_len = 1, ans_l = 0;
        for(int L = 2; L <= len; L ++) {  // 枚举回文串的长度
            for(int i = 0; i < len; i ++) { // 枚举回文串的左边界
                int j = i + L - 1;  // 回文串的右边界
                if(j >= len) break;

                if(s[i] == s[j]) {
                    if(L == 2)
                        dp[i][j] = true;
                    else dp[i][j] = dp[i + 1][j - 1];
                    if(dp[i][j] && L > ans_len) {
                        ans_len = L;
                        ans_l = i;
                    }
                }
                else dp[i][j] = false;
                // cout << "i: " << i << " L: " << L << endl;
                // cout << "sub_s: " << s.substr(i, L) << ' ' << dp[i][j] << endl;
            }
        }

        return s.substr(ans_l, ans_len);
    }
};

int main() {
    Solution s;
    cout << s.longestPalindrome("ac") << endl;
}