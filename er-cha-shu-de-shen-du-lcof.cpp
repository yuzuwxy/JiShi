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


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public: 
    int ans = 0;
    void dfs(TreeNode* node, int deep) {
        if(node == nullptr) {
            ans = max(ans, deep);
            return;
        }
        deep ++;
        dfs(node->left, deep);
        dfs(node->right, deep);
    }
    int maxDepth(TreeNode* root) {
        int deep = 0;
        if(root == nullptr) return deep;

        dfs(root, deep);

        return ans;
    }
};


int main() {
    
    return 0;
}
