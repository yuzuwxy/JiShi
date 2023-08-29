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

class MinStack {
public:
    /** initialize your data structure here. */
    int minStack[20000] = {0};
    int s[20000] = {0};
    int min_top = -1, s_top = -1;
    MinStack() {

    }
    
    void push(int x) {
        s[++ s_top] = x;
        if(min_top == -1) {
            minStack[++min_top] = s_top;
        }
        else {
            if(x < s[minStack[min_top]])
                minStack[++min_top] = s_top;
        }
    }
    
    void pop() {
        if(s_top == -1) return;
        if(minStack[min_top] == s_top) 
            min_top--;
        s_top --;
    }
    
    int top() {
        if(s_top == -1) return -1;
        return s[s_top];
    }
    
    int min() {
        if(min_top == -1) return -1;
        return s[minStack[min_top]];
    }
};

int main() {
    
    return 0;
}
