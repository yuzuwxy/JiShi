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
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        int l = 0, r = len - 1;

        while(l < r) {
            int mid = (l + r) >> 1;
            if(nums[mid] >= nums[l] && nums[mid] > nums[r])
                l = mid + 1;
            else r = mid;
        }
        int k = l;

        l = 0, r = k - 1;   
        while(l < r) {  // 升序
            int mid = (l + r) >> 1;
            if(nums[mid] < target) l = mid + 1;
            else r = mid;
        }
        if(nums[l] == target) return l;

        l = k, r = len - 1;
        while(l < r) {  // 升序
            int mid = (l + r) >> 1;
            if(nums[mid] < target) l = mid + 1;
            else r = mid;
        }
        if(nums[l] == target) return l;

        return -1;

    }
};

// class Solution {
// public:
//     int search(vector<int>& nums, int target) {
//         int len = nums.size();
//         int l = 0, r = len - 1;

//         if(len == 0) return -1;

//         while(l < r) {
//             int mid = (l + r) >> 1;
//             if(nums[mid] == target) return mid;

//             if(nums[l] <= nums[mid]){    // 说明前半部分是有序的
//                 if(target >= nums[l] && target <= nums[mid]) r = mid;
//                 else l = mid + 1;
//             }
//             else {  // 后半部分是有序的
//                 if(target >= nums[mid] && target <= nums[r]) l = mid;
//                 else r = mid - 1;
//             }
//         }
//         if(nums[l] == target) return l;
//         return -1;
//     }
// };

int main() {
    
    return 0;
}
