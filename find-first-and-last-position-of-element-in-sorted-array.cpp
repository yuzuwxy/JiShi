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
    vector<int> searchRange(vector<int>& nums, int target) {
        // 就是找到大于target的最小数和小于target的最大数
        int len = nums.size();
        vector<int> ans = {-1, -1};
        if(len == 0) return ans;
        if(len == 1) {
            if(nums[0] == target) ans[0] = 0, ans[1] = 0;
            return ans;
        }
        if(nums[0] == target) ans[0] = 0;
        else {
            // 找不小于target的最大数
            int l = 0, r = len - 1;
            while(l < r) {
                int mid = (l + r) >> 1;
                if(nums[mid] < target) l = mid + 1;
                else r = mid;
            }
            if(nums[l] == target) ans[0] = l;
            else return ans;
            // cout << l << endl;
        }

        if(nums[len - 1] == target) ans[1] = (len - 1);
        else {
            // 找大于target的最小数
            int l = 0, r = len - 1;
            while(l < r) {
                int mid = (l + r) >> 1;
                if(nums[mid] > target) r = mid;
                else l = mid + 1;
            }
            // cout << l << endl;
            // if(nums[l - 1] == target) ans[1] = (l - 1);
            ans[1] = l > 0 ? ((nums[l - 1] == target) ? (l - 1) : -1) : -1;
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = {5,7,7,8,8,10};
    int target = 6;
    vector<int> ans = s.searchRange(nums, target);
    cout << ans[0] << ' ' << ans[1] << endl;
    return 0;
}
