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
    vector<int> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> ans;
        q.push(root);
        if(root == nullptr) return ans;
        while(!q.empty()){
            TreeNode *t = q.front(); q.pop();
            ans.push_back(t->val);
            if(t->left != nullptr) q.push(t->left);
            if(t->right != nullptr) q.push(t->right);
        }
        return ans;
    }
};

int main() {
    
    return 0;
}
