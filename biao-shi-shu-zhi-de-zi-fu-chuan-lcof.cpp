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
    // 某位字符是0-9
    bool isDigit(char c) {
        return c >= '0' && c <= '9';
    }
    // 判断'.xxxx'这种小数形式，后面至少一位数字
    bool isDecimal(int &i, string s, int len) {
        bool ans = true;
        if(s[i] == '.') {
            i ++;
            if(isDigit(s[i])) i ++;
            else ans = false;
            while(i <= len && isDigit(s[i])) i ++;
        }
        else ans = false;
        return ans;
    }
    // 判断整数部分
    bool isInteger(int &i, string s, int len) {
        bool ans = true;
        while(i <= len && isDigit(s[i])) {
            i ++;
        }
        return ans;
    }
    bool isNumber(string s) {
        int i = 0;
        int len = s.size();
        bool ans = true;
        // 略去前导空格
        while(s[i] == ' ' && i < len) i ++;

        // 略去后缀空格
        len --;
        while(s[len] == ' ' && len > i) len --;

        // 可选的正负号
        if(s[i] == '+' || s[i] == '-') i ++;
        // 数值部分
        if(s[i] == '.' || isDigit(s[i]))  {
            if(s[i] == '.') {
                ans = isDecimal(i, s, len);
            } 
            else if(isDigit(s[i])) {
                ans = isInteger(i, s, len);
                if(i <= len)
                    if(s[i] == '.') {       // .后面可以不跟数字也可以至少一位数字
                        i ++;
                        if(isDigit(s[i])) ans = isInteger(i, s, len);
                    }
            }
            if(i <= len && ans) {
                if(s[i] == 'E' || s[i] == 'e') {
                    i ++;
                    if(i <= len) {
                        if(s[i] == '+' || s[i] == '-') i ++;
                        if(i <= len) ans = isInteger(i, s, len);
                        else ans = false;
                    }
                    else ans = false;
                }
                else ans = false;
            }
        }
        else ans = false;
        if(i <= len) ans = false;

        return ans;
    }
};

int main() {
    Solution s;
    s.isNumber("-1E-16");
    return 0;
}
