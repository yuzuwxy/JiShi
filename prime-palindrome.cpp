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

class Solution {
public:
    bool palindrome(int n) {
        if(n % 10 == 0) return false;
        int reverse_n = 0;
        while(reverse_n < n) {
            reverse_n = reverse_n * 10 + n % 10;
            n /= 10;
        }
        return reverse_n == n || reverse_n / 10 == n;
    }
    int primePalindrome(int n) {
        bool pp[100000000 + 1] = {0};
        bool vis[100000000 + 1]  = {0};
        int prime[10000000 + 1] = {0};
        
        int cnt = 0;
        for(int i = 2; i <= 100000000 + 1; i ++) {
            if(!vis[i]) prime[cnt++] = i, pp[i] = true;
            for(int j = 0; j < n && i * prime[j] <= 100000000; j ++) {
                vis[i * prime[j]] = true;
                if(i % prime[j] == 0) break;
            }
        }

        for(int i = 0;i < cnt; i ++)
            cout << prime[i] << ' ';
        cout << endl;

        return 1;
    }
};

int main() {
    Solution s;
    s.primePalindrome(1);
    return 0;
}
