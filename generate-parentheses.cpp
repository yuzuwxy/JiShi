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

    void function(int count, int n, int top, string cur, vector<string> &ans) {
        if(count == n && top == -1) {
            ans.push_back(cur);
            return;
        }
        if(top < -1) return;

        function(count, n, top - 1, cur + ")", ans);
        if(count < n)
            function(count + 1, n, top + 1, cur + "(", ans);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        function(1, n, 0, "(", ans);
        return ans;
    }
};

int main() {
    Solution s;
    s.generateParenthesis(3);
    
    return 0;
}
