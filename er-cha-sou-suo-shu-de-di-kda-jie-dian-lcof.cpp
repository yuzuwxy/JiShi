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
private:
    int ans;
public:
    void dfs(TreeNode* node, int &k) {
        if( node == nullptr) return ;
        if(k == 0) return;

        dfs(node->right, k);
        k --;
        if(k == 0) ans = node->val;
        dfs(node->left, k);
    }
    int kthLargest(TreeNode* root, int k) {
        
        dfs(root, k);

        return ans;
    }
};

int main() {
    
    return 0;
}
