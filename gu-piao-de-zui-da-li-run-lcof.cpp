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
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if(len <= 1) return 0;

        int minn = prices[0];

        int an = 0;
        for(int i = 1; i < len; i ++) {
            if(prices[i] < minn) minn = prices[i];
            an = max(an, ((prices[i] > minn) ? (prices[i] - minn) : 0));
        }
        
        return an;
    }
};

int main() {
    
    return 0;
}
