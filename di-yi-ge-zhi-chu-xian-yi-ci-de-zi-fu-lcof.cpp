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
    char firstUniqChar(string s) {
        int len = s.size();
        char ans = ' ';
        int vis[256] = {0};
        for(int i = 0; i < len; i ++)
            vis[s[i]] ++;
        
        for(int i = 0; i < len; i ++)
            if(vis[s[i]] == 1) {
                ans = s[i];
                break;
            }
        
        return ans;
    }
};

int main() {
    
    return 0;
}
