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
    vector<string> ans;
    vector<bool> vis;
    void recursion(string s, int cur_id, int len, string& cur_s) {
        if(cur_id == len) {
            ans.push_back(cur_s);
            return ;
        }

        for(int j = 0; j < len; j ++) {
            if(vis[j]) continue;
            if(j > 0 && s[j] == s[j - 1] && !vis[j - 1]) continue;

            vis[j] = true;
            cur_s.push_back(s[j]);
            recursion(s, cur_id + 1, len, cur_s);
            cur_s.pop_back();
            vis[j] = false;
        }
    }

    vector<string> permutation(string s) {
        int len = s.length();
        vis.resize(len);
        sort(s.begin(), s.end());
        string cur_s = "";
        recursion(s, 0, len, cur_s);

        return ans;
    }
};

int main() {
    
    return 0;
}
