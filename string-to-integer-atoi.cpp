#include <iostream>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstdlib>
#include<cctype>
#include<vector>
#include<map>
#include<queue>

#define MAXN (int)1e5
#define ll long long

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int ans = 0;
        int i = 0;
        int len = s.size();
        // 丢弃无用的前导空格
        while(s[i] == ' ' && i < len)
            i ++;
        // 检查是整数还是负数，读取符号
        if(i >= len) return 0;
        bool neg = false;
        s[i] == '-' ? (neg = true, i ++) : (s[i] == '+' ? i++ : neg = false);
        // 读取字符直到到达下一个非数字字符或到达输入的结尾
        while( i < len && isdigit(s[i])) {
            if(ans / 10000000000 )
                return neg ? INT_MIN : INT_MAX;
            
            if(ans > INT_MAX / 10 || ans < INT_MIN / 10)
                return neg ? INT_MIN : INT_MAX;

            int digit = s[i] - '0';
            if(ans == INT_MAX / 10 || ans == INT_MIN / 10) {
                if(neg && digit > 8)
                    return INT_MIN;
                if(!neg && digit > 7)
                    return INT_MAX;
            }
            ans =  ans * 10 + (neg ? (-digit) : digit);
            i ++;
        }

        return ans;    
    }
};

int main() {
    Solution s;
    string str;
    // cout << INT_MAX << " "  << INT_MIN << endl;
    while(cin >> str) {
    // cin >> str;
    cout << s.myAtoi(str) << endl;
    }
    return 0;
}

