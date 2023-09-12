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
    bool isStraight(vector<int>& nums) {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        int i;
        while(i < len && nums[i] == 0) i ++;
        int zero = i;
        i++;
        for(i; i < len; i ++) {
            if(nums[i] - nums[i - 1] != 1) zero -= nums[i] - nums[i - 1] - 1;
            if(zero < 0) break;
        }
        if(zero < 0) return false;
        return true;
    }
};

int main() {
    
    return 0;
}
