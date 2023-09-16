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
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return 0;
        if(len == 1) return nums[0];

        vector<int> pre_sum(len);
        pre_sum[0] = nums[0];
        for(int i = 1; i < len; i ++)
            pre_sum[i] = nums[i] + pre_sum[i - 1];

        int minn = 0;
        int an = -(1e6 + 3);
        for(int i = 0; i < len; i ++) {
            an = max(an, (pre_sum[i] - minn));
            minn = min(pre_sum[i], minn);
        }

        return an;
    }
}; */

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int pre = 0, ans = nums[0];
        int len = nums.size();
        for(int i = 0; i < len; i ++) {
            pre = max(nums[i] + pre, nums[i]);
            ans = max(pre, ans);
        }
        return ans;
    }
};

int main() {
    
    return 0;
}
