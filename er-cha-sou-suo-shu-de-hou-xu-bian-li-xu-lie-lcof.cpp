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
    bool dfs(vector<int>& postorder, int l, int r) {
        if(l == r) return true;

        int root_val = postorder[r];    // 根的值
        int j = r - 1;
        // 如果是二叉搜索树，[l, j]都小于root_val
        while(postorder[j] > root_val && j >= l) j --;
        bool flag = true;
        for(int i = l; i <= j; i ++) 
            if(postorder[i] > root_val){
                flag = false;
                break;
            }
        if(!flag) return false;
        
        return dfs(postorder, l, j) && dfs(postorder, j + 1, r - 1);   
    }


    bool verifyPostorder(vector<int>& postorder) {
        int len = postorder.size();
        if(len == 0) return false;
        return dfs(postorder, 0, len - 1);
    }
};

int main() {
    
    return 0;
}
