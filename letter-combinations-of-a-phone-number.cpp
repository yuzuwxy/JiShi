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
    map<int, string> m = {
        {2, "abc"}, {3, "def"}, {4, "ghi"}, {5, "jkl"},
        {6, "mno"}, {7, "pqrs"}, {8, "tuv"}, {9, "wxyz"},
    };
    void function(int level, int len, string cur, string digits, vector<string> &ans) {
        if(level == len) {
            ans.push_back(cur);
            return;
        }
        // cout << level << endl;
        // cout << digits[level] - '0' << endl;
        for(char letter : m[digits[level] - '0']) {
            cur.push_back(letter);
            function(level + 1, len, cur, digits, ans);
            cur.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        int len = digits.size();
        vector<string> ans;
        
        function(0, len, "", digits, ans);

        // for(string str : ans)
        //     cout << str << ", ";
        // cout << endl;
        return ans;
    }
};

int main() {
    Solution s;
    s.letterCombinations("23");
    return 0;
}
