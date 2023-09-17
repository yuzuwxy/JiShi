#include<iostream>
#include<string>

using namespace std;

/* int main() {
    int T;
    cin >> T;
    while(T --) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        if(n < 4) {
            cout << "NO\n";
            continue;
        }
        int i = 0, start = 0;
        while(s[i] == 'm' || s[i] == 'M') i++;
        if(i == start) {cout << "NO\n"; continue;}
        start = i;
        while(s[i] == 'e' || s[i] == 'E') i ++;
        if(i == start) {cout << "NO\n"; continue;}
        start = i;
        while(s[i] == 'o' || s[i] == 'O') i ++;
        if(i == start) {cout << "NO\n"; continue;}
        start = i;
        while(s[i] == 'w' || s[i] == 'W') i ++;
        if(i == start) {cout << "NO\n"; continue;}

        cout << "YES\n";
    }
    return 0;
} */
// 但是我还是想不通为什么前面的不对，想复杂了。为啥啊。。。
// 为什么想不到去重呢？？
int main() {
    int T;
    cin >> T;
    while(T --) {
        int n; cin >> n;
        string s; cin >> s;
        if(n < 4) { cout << "NO\n"; continue; }
        for(int i = 0; i < n; i ++)
            if(s[i] >= 'A' && s[i] <= 'Z') s[i] = s[i] - ('A' - 'a');
        string meow = "";
        meow.push_back(s[0]);
        for(int i = 1; i < n; i ++)
            if(s[i] != s[i - 1]) meow.push_back(s[i]);
        // cout << "meow" << meow << endl;
        if(meow == "meow") cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}