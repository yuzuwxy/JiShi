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

int num[10 * MAXN + 3];

int mid_num(int a, int b, int c) {
    int mid;
    if((a >= b && a <= c) || (a >= c && a <= b)) mid = a;
    else if((b >= a && b <= c) || ( b <= a && b >= c)) mid = b;
    else if((c >= a && c <= b) || (c >= b && c <= a)) mid = c;

    return mid;     
}

int main() {
    int N;
    scanf("%d", &N);
    ll n = (N << 1) - 1;

    for(int i = 0; i < n; i ++) {
        scanf("%d", &num[i]);
    }
    
    for(int i = n - 1; i > 0; i-= 2) {

        for(int j = 0; j < i - 1; j ++) {
            num[j] = mid_num(num[j], num[j + 1], num[j + 2]);
            // cout << "j: " << j << " num: " << num[j] <<  ' ';
        }
        // cout << endl;
    }
    printf("%d\n", num[0]);
    return 0;
}
