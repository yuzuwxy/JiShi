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
    int missingNumber(vector<int>& nums) {
        int len = nums.size();
        int ans = len;
        for(int i = 0; i < len; i ++)
            if(nums[i] != i) {
                ans = i;
                break;
            }
        return ans;
    }
};

int main() {
    
    return 0;
}
