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
    string intToRoman(int num) {
        string ans = "";
        int qian = num / 1000;
        int bai = (num % 1000) / 100;
        int shi = (num % 100) / 10;
        int ge = num % 10;

        // 千
        for(int i = 0; i < qian; i ++)
            ans.push_back('M');
        // 百
        if(bai == 4) ans.append("CD");
        else if(bai == 9) ans.append("CM");
        else {
            for(int i = 0; i < bai / 5; i ++)
                ans.push_back('D');
            for(int i = 0; i < bai % 5; i ++)
                ans.push_back('C');
        }
        // 十
        if(shi == 4) ans.append("XL");
        else if(shi == 9) ans.append("XC");
        else {
            for(int i = 0; i < shi / 5; i ++)
                ans.push_back('L');
            for(int i = 0; i < shi % 5; i ++)
                ans.push_back('X');
        }
        // 个
        if(ge == 4) ans.append("IV");
        else if(ge == 9) ans.append("IX");
        else {
            for(int i = 0; i < ge / 5; i ++)
                ans.push_back('V');;
            for(int i = 0; i < ge % 5; i ++)
                ans.push_back('I');;
        }
        return ans;
    }
};

int main() {
    Solution s;
    int x;
    while(cin >> x) 
        cout << s.intToRoman(x) << endl;
    return 0;
}
