#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>

#define NO() {cout << "NO\n"; return;}
#define YES() {cout << "YES\n"; return;}

using namespace std;

void process() {
    int n;
    string s;
    cin >> n >> s;
    // 以一个仅包含m或M的非空序列开头
    if(n == 0)  NO()
    if(s[0] != 'm' && s[0] != 'M') 
        NO()

    // 包含仅包含w或W的非空序列并以该序列结尾
    if(s[n - 1] != 'W' && s[n - 1] != 'w') 
        NO()

    char meow[4] = {'m', 'e', 'o', 'w'};
    int j = 0;
    for(int i = 0; i < n; i ++) {
        // cout << (s[i] == meow[j] || s[i] == (meow[j] + 'A' - 'a')) << endl;
        if(s[i] != meow[j] && s[i] != (meow[j] + 'A' - 'a') ) {
            // "接下来"
            if(s[i] == meow[j + 1]|| s[i] == (meow[j + 1] + 'A' - 'a')) j = j + 1;
            else NO()
        }
    }
    YES()
}

int main() {
    int T;
    cin >> T;
    for(int i = 1; i <= T; i ++) {
        process();
    }
}