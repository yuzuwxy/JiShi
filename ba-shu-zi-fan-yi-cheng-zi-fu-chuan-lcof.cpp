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
    bool isLetter(int b1, int b2) {
        cout << (b2 * 10 + b1) << endl;
        return ((b2 * 10 + b1) <= 25) && b2 != 0;
    }
    int translateNum(int num) {
        if(num == 0) return 1;
        vector<int> bit;
        while(num) {
            bit.push_back(num % 10);
            num /= 10;
        }
        reverse(bit.begin(), bit.end());
        int len = bit.size();

        vector<int> dp(len + 1);
        dp[0] = 1;dp[1] = 1;

        for(int i = 2; i <= len; i ++) {
            dp[i] = dp[i - 1] + (isLetter(bit[i - 1], bit[i - 2]) ? dp[i - 2] : 0);
        }
        // for(int i = 1; i <= len; i ++)
        //     cout << dp[i] <<' ';
        return dp[len];

        // for(int i = 0; i < len; i ++)
        //     cout << bit[i];
        // cout << endl;
        // return num;
    }
};

int main() {

    Solution s;
    cout << s.translateNum(12258) << endl;
    
    return 0;
}
