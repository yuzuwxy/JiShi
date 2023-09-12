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
    vector<int> temp;   // 排序好的数组

    int partition(vector<int>& nums, int l, int r) {
        if( l >= r )  return 0;

        int mid = (l + r) >> 1;
        // 分成两部分，每部分内部的+两部分之间的逆序对
        int ans = partition(nums, l, mid) + partition(nums, mid + 1, r);
        temp.clear();
        int i = l, j = mid + 1;
        while(i <= mid && j <= r) {
            if(nums[i] <= nums[j]) {
                ans += (j - mid) - 1;
                temp.push_back(nums[i]);
                i ++;
            }
            else {
                temp.push_back(nums[j]);
                j ++;
            }
        }
        for(int k = i; k <= mid; k ++) {
            temp.push_back(nums[k]);
            ans += (j - mid) - 1;
        }
        for(int k = j; k <= r; k ++)
            temp.push_back(nums[k]);
        

        copy(temp.begin(), temp.end(), nums.begin() + l);
        return ans;
    }

    int reversePairs(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return 0;

        return partition(nums, 0, len - 1);
    }  

};

int main() {
    
    return 0;
}
