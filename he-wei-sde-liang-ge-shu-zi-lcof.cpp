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
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();

        int i = 0, j = len - 1;
        vector<int> ans;
        while(i < j) {
            if(nums[i] + nums[j] == target) {
                ans.push_back(nums[i]);
                ans.push_back(nums[j]);
                break;
            }
            else if(nums[i] + nums[j] < target) i ++;
            else if(nums[i] + nums[j] > target) j --;
        }
        return ans;
    }
};

int main() {
    
    return 0;
}
