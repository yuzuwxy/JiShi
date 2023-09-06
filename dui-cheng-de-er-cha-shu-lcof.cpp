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

    bool isMatch(TreeNode *left, TreeNode *right) {
        if(left == nullptr && right == nullptr) return true;
        if(left == nullptr) return false;
        if(right == nullptr) return false;
        if(left -> val != right->val) return false;

        return isMatch(left->right, right->left) && isMatch(left->left, right->right);
    }

    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) return true;

        return isMatch(root->left, root->right);
    }
};

int main() {
    
    return 0;
}
