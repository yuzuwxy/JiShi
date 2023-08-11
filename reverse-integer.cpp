#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        while(x) {
            if(ans < INT_MIN / 10 || ans > INT_MAX / 10)
                return 0;
            ans = ans * 10 + x % 10;
            x /= 10;
        }
        return ans;
    }
};

int main() {
    Solution s;
    s.reverse(1);
}