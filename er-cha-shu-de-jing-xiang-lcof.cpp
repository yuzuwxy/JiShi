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
    void swapp(TreeNode* node) {
        if(node == nullptr) return;

        TreeNode *p = node->left;
        node->left = node->right;
        node->right = p;
        swapp(node->left);
        swapp(node->right);
    }

    TreeNode* mirrorTree(TreeNode* root) {
        swapp(root);

        return root;
    }
};

int main() {
    
    return 0;
}
