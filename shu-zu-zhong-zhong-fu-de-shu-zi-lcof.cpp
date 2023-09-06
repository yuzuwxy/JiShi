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
    int findRepeatNumber(vector<int>& nums) {
        int digit[100000 + 7] = {0};
        int len = nums.size();
        int ans = 0;
        for(int i = 0; i < len; i ++) {
            if(digit[nums[i]] != 0) {
                ans = nums[i];
                break;
            }
            digit[nums[i]] ++;
        }
        return ans;
    }
};

// class Solution {
// public:
//     int findRepeatNumber(vector<int>& nums) {
//         int i = 0;
//         while(i < nums.size()) {
//             if(nums[i] == i) {
//                 i++;
//                 continue;
//             }
//             if(nums[nums[i]] == nums[i])
//                 return nums[i];
//             swap(nums[i],nums[nums[i]]);
//         }
//         return -1;
//     }
// };


int main() {
    
    return 0;
}
