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
    int numWays(int n) {
        int mod = 1e9 + 7;
        int dp[3] = {1, 1};
        for(int i = 2; i <= n; i ++) {
            dp[i % 2] = (dp[i % 2] % mod + dp[(i + 1) % 2] % mod) % mod;
        }
        return dp[n % 2];
    }
};

int main() {
    
    return 0;
}
