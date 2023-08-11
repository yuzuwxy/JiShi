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

// class Solution {
// public:
//     bool isPalindrome(int x) {
//         if(x < 0) return false;

//         int stack[20] = {0};
//         int top = 0;
//         int _x = x;

//         while(_x){
//             stack[top ++] = _x % 10;
//             _x /= 10;
//         }
//         int ans = 0;
//         for(int i = 0; i < top; i ++)
//             ans = ans * 10 + stack[i];

//         return ans == x;
//     }
// };

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 || (x != 0 && x % 10 == 0)) return false;

        int reverse_x = 0;

        while(reverse_x < x){
            reverse_x = reverse_x * 10 + x % 10;
            x /= 10;
        }
    
        return reverse_x == x || reverse_x / 10 == x;
    }
};

int main() {
    Solution s;
    cout << s.isPalindrome(10) << endl;
    return 0;
}
