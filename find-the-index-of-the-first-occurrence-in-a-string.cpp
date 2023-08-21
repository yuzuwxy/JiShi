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
    void getNext(string p, int next[]) {
        int j = -1, i = 0, len = p.size();
        next[0] = -1;
        while(i < len) {
            if(j == -1) {j ++, i ++; next[i] = j;}
            else if(p[i] == p[j]) {j ++, i ++; next[i] = j;}
            else j = next[j];
        }

    }
    int strStr(string haystack, string needle) {
        int next[10007] = {0};
        getNext(needle, next);
        int len_p = needle.size();
        int len_s = haystack.size();
        int s = 0, p = 0;
        while( s < len_s && p < len_p) {
            if(haystack[s] == needle[p]) s ++, p ++;
            else {
                p = next[p];
                if(p == -1) s ++, p = 0;
            }
        }
        if(p == len_p) return s - len_p;
        else return -1;
    }
};

int main() {
    Solution s;
    cout << s.strStr("sadbutsad", "sad") << endl;
    return 0;
}
