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

int main() {
    string s[200];
    string a, b;
    int cnt = 0;
    do{
        cin >> s[cnt ++];
    }while(getchar() == ' ');

    cin >> a >> b;

    for(int i = 0; i < cnt; i ++) {
        if(i != 0) cout << ' ';
        if(s[i] == a) cout << b;
        else cout << s[i];
    }
    cout << endl;

    return 0;
}

// int main() {
//     string s, a, b;
//     getline(cin, s);
//     cin >> a >> b;
//     int len = s.size();
//     string ans, temp;
//     for(int i = 0; i < len; i ++) {
//         if(s[i] == ' ' || s[i] == 13) {
//             if(ans != "") ans.push_back(' ');
//             if(temp == a) ans.append(b);
//             else ans.append(temp);
//             temp = "";
//         }
//         else temp.push_back(s[i]);
//     }
//     cout << ans << endl;
//     return 0;
// }
