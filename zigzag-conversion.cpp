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

class Solution {
public:
    string convert(string s, int numRows) {
        char ans_c[1003][1003];                                         // 分行存储变形后每行的字符
        int count[1003] = {0};                                          // 用于记录每行的字符个数（下标）
        int len = s.size();
        int k = 0;                                                      // 行数实际上是从0开始
        bool flag = true;                                               // 控制当前行数是+还是-
        for(int i = 0; i < len; i ++){
            ans_c[k][count[k]] = s[i];

            count[k] ++;

            if(flag) k++;       
            else k--;

            if(k == numRows) k = max(numRows - 2, 0), flag = false;     // 加到最后一行，接着往后遍历应该开始-，直接到最后一行的上一行
            else if(k < 0) k = min(1, numRows - 1), flag = true;        // 减到第一行（下标为0），要开始加，直接跳到第二行（下表为1）
        }

        string ans = "";
        for(int i = 0; i < numRows; i ++){
            ans.append(ans_c[i], count[i]);                             // 把分出来的每一行依次添加到字符串中
        }
        return ans;
    }
};

int main() {
    Solution s;
    cout << s.convert("ABC", 1) << endl;

    return 0;
}

