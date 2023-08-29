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

// class Solution {
// public:
//     string reverseLeftWords(string s, int n) {
//         string ans;
//         int len = s.size();
        
//         for(int i = n; i < len; i ++)
//             ans.push_back(s[i]);
//         for(int i = 0; i < n; i ++)
//             ans.push_back(s[i]);
        
//         return ans;
//     }
// };

class Solution {
public:
    string reverseLeftWords(string s, int n) {
        int len = s.size();

        int l = 0, r = len - 1;
        int mid = (l + r + 1) >> 1;
        for(int i = l; i < mid; i ++) {
            char temp = s[i];
            s[i] = s[r - i];
            s[r - i] = temp;
        }
        cout << s << endl;
        r = len - n - 1;
        mid = (l + r + 1) >> 1;
        for(int i = l; i < mid; i ++) {
            char temp = s[i];
            s[i] = s[r - i];
            s[r - i] = temp;
        }
        cout << s << endl;
        l = len - n;
        r = len - 1;
        mid = (l + r + 1) >> 1;
        for(int i = l; i < mid; i ++) {
            char temp = s[i];
            s[i] = s[r - i + l];
            s[r - i + l] = temp;
        }
        return s;
    }
};

int main() {
    
    return 0;
}
