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

    // 要判断divisor * mid 和 dividend的关系。mid是在二分法中假设的商
    // 但是如果直接mid个divisor加起来会超时
    // 所以用了和快速幂类似的思路——快速乘
    // 用来判断divisor * mid <= dividend, 如果大于返回false
    bool quickAdd(int divisor, int mid, int dividend) {
        int result = 0, add = divisor;      
        while(mid) {    // 就像
            if(mid & 1) {
                // 因为result、add和dividend都是负数
                // 所以实际上应该是result + add < dividend的时候说明mid太大了。
                if(result < dividend - add)
                    return false;
                result += add;
            }
            if(mid != 1) {
                // 同前面result
                if(add < dividend - add) return false;
                add += add;
            }
            mid >>= 1;
        }
        return true;
    }
    int divide(int dividend, int divisor) {
        // 超界的情况只可能是被除数和除数一个是INT_MIN
        // 因为|INT_MIN| > INT_MAX
        if(dividend == INT_MIN) {
            if(divisor == 1) return dividend;
            if(divisor == -1) return INT_MAX;
        }

        if(divisor == INT_MIN) return dividend == INT_MIN ? 1 : 0;

        if(dividend == 0) return 0;

        // 正常的情况使用二分查找可以满足的商
        bool neg = (dividend < 0) ^ (divisor < 0);
        if(dividend > 0) dividend = -dividend;
        if(divisor > 0) divisor = -divisor;

        // 商的可能范围是1-INT_MAX
        int left = 1, right = INT_MAX, ans = 0;
        while(left <= right) {
            // 当然可以(left + right)>>1, 但是可能会溢出
            int mid = left + ((right - left) >> 1);
            bool check = quickAdd(divisor, mid, dividend);
            if(!check) right = mid - 1;
            else {
                ans = mid;
                if(ans == INT_MAX) break;
                left = mid + 1;
            }
        }
        return neg ? -ans : ans;
    }
};

int main() {
    
    return 0;
}