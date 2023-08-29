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
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int len = s.size();
        if(len == 0) return "";
        len --;
        int i = 0, j = 0;
        while(s[i] == ' ' && i <= len) i ++;
        j = i;
        while(s[len] == ' ' && len > i) len --;
        if(len == i) return "";
        string ans = "";
        while(i <= len && j <= len) {
            if(s[i] == ' ') i ++, j ++;
            else if(s[j] == ' ') {
                reverse(s.begin() + i, s.begin() + j);
                ans.append(s.substr(i, j - i));
                ans.push_back(' ');
                j ++;
                i = j;
            }
            else j ++;
        }
        if(s[i] != ' ') {
            reverse(s.begin() + i, s.begin() + j);
            ans.append(s.substr(i, j - i));
        }
        return ans;
    }
};

int main() {
    
    return 0;
}
