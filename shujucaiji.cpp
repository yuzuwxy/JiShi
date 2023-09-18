#include <iostream>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<set>

#define MAXN (int)1e5
#define ll long long

using namespace std;

int tree[40000 + 7];    // 线段树中存放上次采集的时间点
int lazy[40000 + 7];

void build() {  // 所有采集点均未采集过，初始值为0
    memset(tree, 0, sizeof(tree));
    memset(lazy, 0, sizeof(lazy));
}

void push_down(int id, int l, int r) {
    if(lazy[id]) {
        lazy[id * 2] = lazy[id];
        lazy[id * 2 + 1] = lazy[id];
        tree[id * 2] = lazy[id];
        tree[id * 2 + 1] = lazy[id];
        lazy[id] = 0;
    }
}

void push_up(int id) {
    if(tree[id * 2] == tree[id * 2 + 1])
        tree[id] = tree[id * 2];
    else tree[id] = -1;
}

int caiji(int id, int l, int r, int x, int y, int c) {
    if(x <= l && y >= r && tree[id] != -1) {
        int ans = (c - tree[id]) * (r - l + 1);
        // cout << ans << endl;
        tree[id] = c;
        lazy[id] = c;
        return ans;
    }

    push_down(id, l, r);    // 查id的子节点
    int mid = (l + r) >> 1, ans = 0;
    if(x <= mid) ans += caiji(id * 2, l, mid, x, y, c);
    if(y > mid)  ans += caiji(id * 2 + 1, mid + 1, r, x, y, c);
    push_up(id);
    return ans;
}

void process() {
    int N, M;
    cin >> N >> M;
    int ans = 0;
    build();

    for(int i = 0; i < M; i ++) {
        int c, l, r;
        cin >> c >> l >> r;
        ans += caiji(1, 1, N, l, r, c);
    }
    cout << ans << endl;
}

int main() {
    int T;
    cin >> T;
    while( T -- ){
        process();
    }
    return 0;
}
