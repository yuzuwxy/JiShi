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

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr) return nullptr;

        TreeNode* ans = root;
        while(ans != nullptr) {
            if(ans->val > max(p->val, q->val)) 
                ans = ans->left;
            else if(ans->val < min(p->val, q->val)) 
                ans = ans->right;
            else if(ans->val >= min(p->val, q->val) && ans->val <= max(p->val, q->val))
                break;
        }

        return ans;
    }
};

int main() {
    
    return 0;
}
