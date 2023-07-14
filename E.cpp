#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>
#include<iomanip>
#include<bits/stdc++.h>

#define MAXN (int)(1e5)

#define NO() {cout << "NO\n"; return;}
#define YES() {cout << "YES\n"; return;}

using namespace std;

int ans = -1;
int n;

int mark[MAXN + 3] = {0};   // 记录下一个相同数字出现的位置
int num[MAXN + 3] = {0};

void dfs(int i, int cut) {
    // cout << i << ' ' << cut << endl;
    if(i >= n) {
        ans = max(ans, cut);
        return;
    }
    if(mark[i] == 0)     // 后面没有相同的数字
        dfs(i + 1, cut);
    else {
        dfs(mark[i] + 1, cut + mark[i] - i + 1);    // 删去这一段
        dfs(i + 1, cut);    // 不删这一段
    }
}

void process() {
    int arr[MAXN + 3];
    cin >> n;
    ans = -1;
    memset(mark, 0, sizeof(mark));
    memset(num, 0, sizeof(num));
    for(int i = 1; i <= n; i ++) {
        cin >> arr[i];
        mark[num[arr[i]]] = i;
        num[arr[i]] = i;
    }

    // for(int i = 1; i <= n; i ++)
    //     cout << mark[i] << ' ';
    // cout << endl;

    dfs(1, 0); 

    cout << ans << endl;  
}

int main() {
    int T;
    cin >> T;   
    while( T --) 
        process();
    return 0;
}