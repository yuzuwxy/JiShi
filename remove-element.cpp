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
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size();

        int i = 0;
        if(len == 0) return 0;
        if(len == 1) {
            if(nums[0] == val) return 0;
            else return 1;
        }
        for(int j = 0; j < len; j ++) {
            if(nums[j] != val) {
                nums[i] = nums[j];
                i ++;
            }
        }
        return i;
    }
};

int main() {
    
    return 0;
}
