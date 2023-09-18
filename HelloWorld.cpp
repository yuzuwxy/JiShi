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

int main() {
    string s = "1234567";
    do {
        cout << s << endl;
    }while(next_permutation(s.begin(), s.end()));
    return 0;
}