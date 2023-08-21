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
    void nextPermutation(vector<int>& nums) {
        if(next_permutation(nums.begin(), nums.end()))
            for (int num : nums) 
                cout << num << " ";
        else sort(nums.begin(), nums.end());
        cout >> endl;
    }
};

int main() {
    vector<int> nums = {3, 2, 1};
    
    // 获取第一个全排列
    // sort(nums.begin(), nums.end());
    // do {
    //     for (int num : nums) {
    //         cout << num << " ";
    //     }
    //     cout << endl;
    // } while (std::next_permutation(nums.begin(), nums.end()));
    if(next_permutation(nums.begin(), nums.end()))
        for (int num : nums) 
            cout << num << " ";
    cout << endl;
    
    return 0;
}

