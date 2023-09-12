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
    bool cmp(int& a, int& b) {
        return to_string(a) + to_string(b) < to_string(b) + to_string(a);
    }
    string minNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);
        int len = nums.size();
        string ans = "";
        for(int i = 0; i < len; i ++) 
            ans.append(to_string(nums[i]));
        return ans;
    }
};

int main() {
    cout << ("3" > "30") << endl;
    return 0;
}
