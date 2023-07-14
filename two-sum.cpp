// https://leetcode.cn/problems/two-sum/

#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstdlib>
#include<vector>
#include<map>
#include<unordered_map>
#include<queue>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> nums_map;
        int len = nums.size();
        for(int i = 0; i < len; i ++ ) {
            int num = nums[i];
            if(nums_map.find(target - num) != nums_map.end()) {
                return {i, nums_map.find(target - num)->second};
            }
            nums_map[num] = i;
        }
        return {};
    }
};