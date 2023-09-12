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
    bool ans = true;
    int deep(TreeNode* node) {
        if(node == nullptr) return 0;


        int deep_l = deep(node->left) + 1;
        int deep_r = deep(node->right) + 1;
        if(abs(deep_l - deep_r) > 1) ans = false;
        return max(deep_l, deep_r);
    }
    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;
        int d = deep(root);
        return ans;
    }
};

int main() {
    
    return 0;
}
