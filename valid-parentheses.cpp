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
    bool isMatch(char s, char top) {
        return (s == ')' && top == '(')
            || (s == ']' && top == '[')
            || (s == '}' && top == '{');
    }

    bool isValid(string s) {
        char stack[10007] = {0};
        int top = 0;
        int len = s.size();

        for(int i = 0; i < len; i ++) {
            if(isMatch(s[i], stack[top]))
                top --;
            else stack[++ top] = s[i];
        }
        if(top == 0) return true;
        return false;
    }
};

int main() {
    
    return 0;
}
