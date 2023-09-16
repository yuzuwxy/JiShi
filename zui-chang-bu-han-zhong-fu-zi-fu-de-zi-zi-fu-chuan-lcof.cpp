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

/* class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.size();
        if(len == 0) return 0;
        int win_l = 0, win_r = 1;
        int ans = 0;
        bool vis[128] = {0}; vis[s[0]] = true;
        while(win_r < len) {
            if(vis[s[win_r]]) {
                ans = max(ans, win_r - win_l);
                while(vis[s[win_r]]) {
                    vis[s[win_l]] = false;
                    win_l ++;
                }
            }
            else {
                vis[s[win_r]] = true;
                win_r ++;
            }
        }
        return ans;
    }
}; */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.size();
        if(len == 0) return 0;
        if(len == 1) return 1;

        vector<int> dp(len + 1);
        int vis[130] = {0};
        dp[0] = 1; vis[s[0]] = 1;
        int ans = 0;
        for(int i = 1; i < len; i ++) {
            int last = vis[s[i]] - 1;   // 上一个数的坐标
            vis[s[i]] = i + 1;
            if(last < i - dp[i - 1]) dp[i] = dp[i - 1] + 1;
            else if(last >= i - dp[i - 1])  dp[i] = i - last;
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};

int main() {
    
    return 0;
}
