#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>

using namespace std;

const int MAXN=100000;

int c[MAXN];
int N, Q, n;

void quest(int k, int layer, int num) {
    // cout << k << ' ' << num << endl;        
    if(num == 0) {
        return;
    }

    if(num == 1) {
        c[k] = 1;
        while(layer <= N) 
            c[k * 2] = 1, layer = layer + 1, k = k * 2;
        return ;
    }
    if(layer == N){
        c[k] = num;
        return;
    }
    int left = 0, right = 0;
    if(num % 2 == 0) left = num / 2, right = num /2;
    else left = num / 2 + 1, right = num / 2;

    quest(k * 2, layer + 1, left);
    quest(k * 2 + 1, layer + 1, right);

    c[k]  = c[k * 2] + c[k * 2 + 1];
}

int main() {
    scanf("%d%d", &N, &Q);
    n = pow(2, N);

    quest(1, 0, Q);
    // int k = 1;
    // c[k] = Q;
    // int layer = 0; 
    // int left = 0, right = 0;
    // while(layer <= N) {
    //     if(c[k] % 2 == 0) left = c[k] / 2, right = c[k] /2;
    //     else left = c[k] / 2 + 1, right = c[k] / 2;
    //     c[k * 2] = left;
    //     c[k * 2 + 1] = right;
    //     layer ++;
        
    // }

    int start = n - 1;

    cout << c[start + 1];
    for(int i = 2; i <= n; i ++) {
        cout <<' ' << c[start + i];
    }
    cout << endl;
    
}