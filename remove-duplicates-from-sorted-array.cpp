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
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        int i = 0;

        if(len == 0) return 0;
        if(len == 1) return 1;

        for(int k = 1; k < len; k ++) {
            cout << "i :" << i << " k: " << k << " nums[i]: " << nums[i] << " nums[j]: " << nums[k] << endl;
            if(nums[k] != nums[i]) {
                i ++;
                nums[i] = nums[k];
            }
        }
        i ++;
        return i;
    }
};

int main() {
    Solution s;
    vector<int> v = {1,1,2};
    cout << s.removeDuplicates(v) << endl;
    return 0;
}
