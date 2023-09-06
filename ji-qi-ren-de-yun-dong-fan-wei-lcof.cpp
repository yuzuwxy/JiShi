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
    int bitSum(int x) {
        int ans = 0;
        while(x) {
            ans += x % 10;
            x /= 10;
        }
        return ans;
    }
    int movingCount(int m, int n, int k) {
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        int ans = 1;
        if(k == 0) return ans;
        q.push(make_pair(0, 0));
        vis[0][0] = true;
        while(!q.empty()) {
            int x = q.front().first, y = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i ++) {
                int nxt_x = x + dir[i][0], nxt_y = y + dir[i][1];
                if(nxt_x >= 0 && nxt_x < m && nxt_y >= 0 && nxt_y < n)
                    if(bitSum(nxt_x) + bitSum(nxt_y) <= k && !vis[nxt_x][nxt_y]) {
                        q.push(make_pair(nxt_x, nxt_y));
                        vis[nxt_x][nxt_y] = true;
                        ans ++;
                    }
            }
        }

        return ans;
    }
};

int main() {
    
    return 0;
}
