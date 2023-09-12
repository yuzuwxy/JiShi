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

#define MAXN (int)1e5
#define ll long long

using namespace std;

class Solution {
public:
    int sumNums(int n) {
        if(n == 0) return 0;

        return n+sumNums(n - 1);
    }
};

// class Solution {
// public:
//     int sumNums(int n) {
//         n && (n += sumNums(n-1));
//         return n;
//     }
// };

int main() {
    
    return 0;
}
