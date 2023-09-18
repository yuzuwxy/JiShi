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

int peo[100];
char graph[103][103];
int M = 0;

int main() {
    int N;
    cin >> N;
    for(int i = 1; i <= N; i ++) {
        int temp;
        cin >> temp;
        peo[i] = peo[i - 1] + temp;
        M = max(M, peo[i]);
    }

    for(int i = 0; i < N; i ++) {
        int x = i, y = M - peo[i];
        if(peo[i] > peo[i + 1])
            graph[y + 1][x] = '\\';
        else if(peo[i] < peo[i + 1])
            graph[y][x] = '/';
        else graph[y][x] = '_';
        // cout << y << ' ' << x << ' ' << graph[y][x]<< endl;
    }
    for(int i = 0; i <= M; i ++) {
        for(int j = 0; j < N; j ++) {
            if(graph[i][j] == 0) cout << ' ';
            else cout << graph[i][j];
        }
        cout << endl;
    }
    return 0;
}
