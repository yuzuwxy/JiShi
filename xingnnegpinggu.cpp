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

int main() {
    int n, t1, t2;
    cin >> n >> t1 >> t2;
    int n1 = 0, n2 = 0, t = 0;
    bool flag1 = true, flag2 = true;
    int max_t = max(t1, t2) * n;
    for(t = 1; t <= max_t; t ++){
        if( t % t1 == 0 && flag1) {   // 当前时刻是大核完成一个任务的时刻
            n1 ++;
            if(t % t2 == 0 && flag2) {
                n2 ++;
                if(n1 + n2 >= n) flag2 = false;
            }
            if(n1 + n2 >= n) flag1 = false;
            if(n1 + n2 >= n && !flag1 && !flag2) break;
        }
        else if( t % t2 == 0 && flag2) {  // 是小核完成任务的时刻
            n2 ++;
            if(t % t1 == 0 && flag1) {
                n1 ++;
                if(n1 + n2 >= n) flag1 = false;
            }
            if(n1 + n2 >= n) flag2 = false;
            if(n1 + n2 >= n && !flag1 && !flag2) break;
        }
    }
    cout << t << ' ' << (n1 + n2) << endl;
    return 0;
}
