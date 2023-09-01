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
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int len = nums.size();
        vector<int> ans;
        if(len == 0 || k == 0) return ans;

        deque<int> q;

        int win_l = 0;
        for(int i = win_l; i < k; i ++) {
            if(q.empty()) q.push_back(i);
            else {
                while(nums[q.back()] < nums[i]) {
                    q.pop_back();
                    if(q.empty()) break;
                }
                q.push_back(i);
            }
        }
        ans.push_back(nums[q.front()]);
        win_l ++;
        while(win_l + k  - 1 < len) {
            if(win_l - 1 == q.front()) {
                q.pop_front();
            }
            int win_r = win_l + k - 1;
            if(!q.empty()) {
                while(nums[q.back()] < nums[win_r]) {
                    q.pop_back();
                    if(q.empty()) break;
                }
                q.push_back(win_r);
            }
            ans.push_back(nums[q.front()]);
            win_l ++;
        }
        return ans;
    }
};


int main() {
    
    return 0;
}
