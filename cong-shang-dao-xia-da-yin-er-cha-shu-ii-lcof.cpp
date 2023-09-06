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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void func(vector<vector<int>> &ans, TreeNode *node, int level) {
        if(node == nullptr) return ;
        if(ans.size() < level) {
            vector<int> cur_level;
            cur_level.push_back(node->val);
            ans.push_back(cur_level);
        }
        else {
            ans[level - 1].push_back(node->val);
        }
        func(ans, node->left, level + 1);
        func(ans, node->right, level + 1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        func(ans, root, 1);
        return ans;
    }
};

int main() {
    
    return 0;
}
