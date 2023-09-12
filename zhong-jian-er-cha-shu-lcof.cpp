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
    map<int, int> hash;

    TreeNode* func(vector<int>& preorder, vector<int>& inorder, int& cur, int l, int r) {
        if(l == r) return nullptr;
        if(cur >= preorder.size()) return nullptr;
        TreeNode* root = new TreeNode(0);
        root->val = preorder[cur ++];
        int idx = hash[root->val];
        // cout << "val: " << root->val << " idx: " << idx << endl;
        root->left = func(preorder, inorder, cur, l, idx);
        root->right = func(preorder, inorder, cur, idx + 1, r);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int len = preorder.size();
        TreeNode* root;

        // 前序遍历值-中序遍历该值的坐标
        for(int i = 0; i < len; i ++) {
            int val = preorder[i];
            int idx = find(inorder.begin(), inorder.end(), val) - inorder.begin();
            hash[val] = idx;
            // cout << "val: " << preorder[i] << " idx: " << idx << endl;
        }
        int cur = 0;
        root = func(preorder, inorder, cur, 0, len);

        return root;
    }
};

int main() {
    
    return 0;
}
