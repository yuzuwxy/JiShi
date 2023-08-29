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

typedef struct peanut{
    int x, y;
    int val;
}peanut;

int m, n, k;
vector<peanut> nuts;

bool cmp(peanut a, peanut b) {
    return a.val >= b.val;
}

int main() {
    cin >> m >> n >> k;
    for(int i = 0; i < m; i ++) 
        for(int j = 0; j < n; j ++) {
            int val;
            cin >> val;
            if(val != 0) {
                peanut nut;
                nut.x = i, nut.y = j, nut.val = val;
                nuts.push_back(nut);
            }
        }

    sort(nuts.begin(), nuts.end(), cmp);

    int t = 0;
    int ans = 0;
    // 摘取花生最多的植株并返回需要的时间
    if((nuts[0].x + 1) * 2 + 1 > k) ans = 0;
    else {
        t += (nuts[0].x + 1) + 1;  // 摘取花生最多的植株需要的时间
        ans += nuts[0].val;
        int plants = nuts.size();
        for(int i = 1; i < plants; i ++) {
            int dist = abs(nuts[i].x - nuts[i - 1].x) + abs(nuts[i].y - nuts[i - 1].y) + 1; // 到达下一个植株并采摘需要的时间
            int back = nuts[i].x + 1;       // 采摘下一个植株返回的时间
            if(t + dist + back> k) break;
            else {
                t += dist;      // 到达下一个植株并采摘
                ans += nuts[i].val;
            }
            // cout << t << endl;
        }
    }

    cout << ans << endl;

    return 0;
}
