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
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i = 0, j = 0;
        stack<int> s;
        int len = pushed.size();
        while(i < len) {
            s.push(pushed[i]);
            while(!s.empty() && s.top() == popped[j]){
                s.pop();
                j ++;
            }
            i ++;
        }
        if(i == len && j == len) return true;
        else return false;
    }
};

int main() {
    
    return 0;
}
