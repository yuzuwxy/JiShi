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
    int romanToInt(string s) {
        int len = s.size();
        s.push_back('0');
        map<char, int> m = {
            {'0', 0}, {'I', 1}, {'V', 5}, {'X', 10},
            {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000},
        };
        int ans = 0;
        for(int i = 0; i < len; i++) {
            char c = s[i];
            if(m[s[i]] >= m[s[i + 1]])
                ans += m[s[i]];
            else ans -= m[s[i]];
        }
        return ans;
    }
};

int main() {
    Solution s;
    string str;
    while(cin >> str) 
        cout << s.romanToInt(str) << endl;
    return 0;
}
