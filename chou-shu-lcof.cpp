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
#include<set>

#define MAXN (int)1e5
#define ll long long

using namespace std;

/* class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ans;
        ans.push_back(1);
        int p2 = 0, p3 = 0, p5 = 0;

        for(int i = 1; i < n; i ++) {
            int num2 = 2 * ans[p2], num3 = 3 * ans[p3], num5 = 5 * ans[p5];
            ans.push_back(min(num2, min(num3, num5)));
            if(num2 == ans[i]) 
                p2 ++;
            if(num3 == ans[i])
                p3 ++;
            if(num5 == ans[i])
                p5 ++;
        }
        return ans[n - 1];
    }
}; */

class Solution {
public:
    int nthUglyNumber(int n) {
        set<long long> uglys;

        uglys.insert(1);
        int count = 0;
        long long num;
        for(long long  i : uglys) {
            num = i;
            count ++;
            uglys.insert(num * 2);
            uglys.insert(num * 3);
            uglys.insert(num * 5);
            if(count == n) break;
        }
        return num;
    }
};

int main() {
    
    return 0;
}
