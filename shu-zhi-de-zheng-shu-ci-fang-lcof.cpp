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
    // 快速幂
    double myPow(double x, int n) {
        double ans = 1;
        long long N = n;
        bool neg = false;
        if(n < 0) N = -n, neg = true;
        while(n) {
            if(N % 2 == 1)
                ans *= x;
            x *= x;
            N /= 2;
        }
        return neg ? -ans : ans;
    }
};

int main() {
    
    return 0;
}
