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

// 就是string-to-integer-atoi.cpp
class Solution {
public:
    int strToInt(string str) {
        // 先把表示数字的字符串摘出来
        int i = 0;
        int len = str.size();
        while(i < len && str[i] == ' ') i ++;

        // 字符串为空或字符串仅包含空白字符
        if(i == len) return 0;
        // 第一个非空格字符不是有效整数字符，也不表示数字正负
        if(!(str[i] >= '0' && str[i] <= '9') && str[i] != '+' && str[i] != '-')
            return 0;
        
        // 提取正负号
        bool neg = false;       // neg为false表示整数，否则表示负数
        if(str[i] == '-') neg = true, i ++;
        else if(str[i] == '+') neg = false, i ++;
        // 除正负号之外的第一个非空格字符不是有效整数字符
        int ans = 0;
        if(!(str[i] >= '0' && str[i] <= '9')) return 0;
        else {
            int bit = 0;
            while(str[i] >= '0' && str[i] <= '9' && i < len) {
                if(bit == 9) break;
                ans = ans * 10 + (str[i] - '0');
                if(ans != 0) bit ++;
                i ++;
            }
            if(str[i] >= '0' && str[i] <= '9') {
                if(ans > INT_MAX / 10) 
                    ans = neg ? INT_MIN : INT_MAX;
                else if(ans == INT_MAX / 10) {
                    if(str[i] - '0' <= 7) {
                        ans = ans * 10 + (str[i] - '0') , i ++;
                        if(i < len) {
                            if(str[i] >= '0' && str[i] <= '9')
                                ans = neg ? INT_MIN : INT_MAX;
                            else ans = neg ? -ans : ans;
                        }
                        else ans = neg ? -ans : ans;
                    }
                    else if(str[i] - '0' == 8) {
                        if(neg) ans = INT_MIN;
                        else ans = INT_MAX;
                    }
                    else ans = neg ? INT_MIN : INT_MAX;
                }
                else {
                    ans = ans * 10 + (str[i] - '0');
                    i ++;
                    if(i < len) {
                        if(str[i] >= '0' && str[i] <= '9')
                            ans = neg ? INT_MIN : INT_MAX;
                        else ans = neg ? -ans : ans;
                    }
                    else ans = neg ? -ans : ans;
                }
            }
            else ans = neg ? -ans : ans;
        }
        return ans;
    }
};

int main() {
    
    return 0;
}
