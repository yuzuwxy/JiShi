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
    vector<string> res;
    string num;
    void dfs(int cur, int len) {
        if(cur == len) {
            res.push_back(num);
            return;
        }

        for(int i = (cur == 0 ? 1 : 0); i <= 9; i ++) {
            num.append(to_string(i));
            dfs(cur + 1, len);
            num.pop_back();
        }
    }
    vector<int> printNumbers(int n) {
        vector<int> ans;
        for(int i = 1; i <= n; i ++) {
            num = "";
            num.clear();
            dfs(0, i);
        }

        for(vector<string>::iterator it = res.begin(); it != res.end(); it ++) 
            ans.push_back(stoi(*it));
        
        return ans;
    }
};

int main() {
    
    return 0;
}
