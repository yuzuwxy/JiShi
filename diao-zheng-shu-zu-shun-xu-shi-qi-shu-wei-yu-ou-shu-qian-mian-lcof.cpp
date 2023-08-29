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
    vector<int> exchange(vector<int>& nums) {
        int len = nums.size();

        int i = 0, j = len - 1;
        while(i < j) {
            if(nums[i] % 2 == 0 && nums[j] % 2 != 0) {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                i ++, j --;
            }else {
                if(nums[i] % 2 != 0) i ++;
                if(nums[j] % 2 == 0) j --;
            }
        }
        return nums;
    }
};

int main() {
    
    return 0;
}
