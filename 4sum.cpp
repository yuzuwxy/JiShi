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

#define MAXN (int)1e5
#define ll long long

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int len = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < len - 3; i ++) {
            for(int j = i + 1; j < len - 2; j ++) {
                int l = j + 1, r = len - 1;

                while(l < r) {
                    ll sum = (ll)nums[i] + (ll)nums[j] + (ll)nums[l] + (ll)nums[r];
                    if(sum == (ll)target) {
                        vector<int> an = {nums[i], nums[j], nums[l], nums[r]};
                        ans.push_back(an);
                        l ++, r --;
                        if(i != j + 1)
                            while(l < r && nums[l] == nums[l - 1]) l ++;
                        while(l < r && nums[r] == nums[r + 1]) r--;
                    }
                    else if(sum < (ll)target) {
                        l ++;
                        if(i != j + 1)
                        while(l < r && nums[l] == nums[l - 1]) l ++;
                    }
                    else {
                        r--;
                        while(l < r && nums[r] == nums[r + 1]) r--;
                    }
                }
                while(j < len - 1 && nums[j] == nums[j + 1]) j ++;
            }
            while(i < len - 1 && nums[i] == nums[i + 1]) i ++;
        }

        return ans;
    }
};

int main() {
    
    return 0;
}
