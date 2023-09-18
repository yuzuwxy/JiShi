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
#include<set>

#define MAXN (int)1e5
#define ll long long

using namespace std;

int N, W, A, B;
int satis[200][2] = {0};
int ans = 0;
int max_satis = 0;
int max_tot = 0;

void dfs(int N_i, int cost, int val) {
    if(cost > W ) return;
    if(cost + (N - N_i) * min(A, B) > W) return;
    if(val + (N - N_i) * max_satis < ans) return;
    if(N_i == N) {
        ans = max(ans, val);
        return ;
    }
    
    dfs(N_i + 1, cost + A, val + satis[N_i][0]);
    dfs(N_i + 1, cost + B, val + satis[N_i][1]);
}

int main() {
    // 表演者个数=要买的奖品个数，最大经费，奖品A价格，奖品B价格
    scanf("%d%d%d%d", &N, &W, &A, &B);
    for(int i = 0; i < N; i ++) {
        scanf("%d%d", &satis[i][0], &satis[i][1]);
        max_satis = max(max_satis, max(satis[i][0], satis[i][1]));
        max_tot += max(satis[i][0], satis[i][1]);
    }

    if(N * min(A, B) > W){cout << 0 << endl; return 0;}  // 没办法买N件
    if(N * max(A, B) <= W) {cout << max_tot << endl; return 0;}
    
    dfs(0, 0, 0);  // 从第1个(下标从0开始)开始搜索，目前花掉的经费为0，得到的满意度为1

    printf("%d\n", ans);
    return 0;
}
