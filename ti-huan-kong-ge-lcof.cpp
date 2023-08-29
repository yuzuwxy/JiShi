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
    string replaceSpace(string s) {
        int len = s.size();
        string new_s;
        for(int i = 0; i < len; i ++) {
            if(s[i] == ' ') new_s.append("%20");
            else new_s.push_back(s[i]);
        }
        return new_s;
    }
};

int main() {
    
    return 0;
}
