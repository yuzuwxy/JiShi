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
    vector<vector<int>> threeSum(vector<int>& nums) {
        int len = nums.size();
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        for(int k = 0; k < len; k ++) {
            if(nums[k] > 0) break;

            int i = k + 1, j = len - 1;
            while(i < j) {
                if(nums[i] + nums[j] + nums[k] == 0) {
                    vector<int> an = {nums[i], nums[k], nums[j]};
                    ans.push_back(an);
                    i ++ , j --;
                    while(i < j && nums[i] == nums[i - 1]) i ++;
                    while(j > i && nums[j] == nums[j + 1]) j --;
                }
                else if(nums[i] + nums[j] < -nums[k]) i ++;
                else j --;
            }
            while(k < len - 1 && nums[k] == nums[k + 1]) k ++;
        }

        return ans;
    }
};

int main() {
    return 0;
}
