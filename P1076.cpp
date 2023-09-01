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

int tower[10000][100] = {0};        // 记录每层每个房间的指示牌的数字
bool stair[10000][100] = {0};        // 记录每层每个房间是否有向上的楼梯
int stairRoom[10000] = {0};         // 记录每层有楼梯房间的个数
int n, m;
int cnt;

int main() {
    cin >> n >> m;      // 层数和每层的房间数
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            int flag, sign;
            scanf("%d%d", &flag, &sign);
            tower[i][j] = sign;
            stair[i][j] = flag;
            if(flag == 1) stairRoom[i] ++;
        }
    }

    cin >> cnt;
    int ans = 0;
    for(int i = 0; i < n; i ++) {
        // cout << "cnt: " << cnt << endl;
        ans = (ans % 20123 + tower[i][cnt] % 20123) % 20123;
        int nxt = 0;
        int sign = tower[i][cnt];
        if(stair[i][cnt])
            nxt = (sign + stairRoom[i] - 1) % stairRoom[i];
        else 
            nxt = (sign - 1) % stairRoom[i] + 1;
        int nxt_idx = cnt;
        while(nxt) {
            nxt_idx = (nxt_idx + 1) % m;
            if(stair[i][nxt_idx]) nxt --;
        }
        cnt = nxt_idx;
    }
    cout << ans << endl;
    return 0;
}
