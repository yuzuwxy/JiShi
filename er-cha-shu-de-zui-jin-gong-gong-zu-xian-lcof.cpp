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

    TreeNode* ans;
    // 定义f(node)为以node为根的子树中是否包含p或q结点
    bool f(TreeNode* node, TreeNode* p, TreeNode* q) {
        if(node == nullptr) return false;
        bool l = f(node->left, p, q);
        bool r = f(node->right, p, q);

        if((l && r) || ((node->val == p->val || node->val == q->val) && (l || r)))
            ans = node;
        
        return l || r || (node->val == p->val || node->val == q->val);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        f(root, p, q);
        return ans;
    }
};

int main() {
    
    return 0;
}
