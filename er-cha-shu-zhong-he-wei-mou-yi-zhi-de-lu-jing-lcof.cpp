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
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> ans;
    void dfs(TreeNode* node, vector<int>& an, int sum, int target, int level) {
        // cout << level << " sum before: " << sum << endl;
        if(node == nullptr) return;
        sum += node->val;
        an.push_back(node->val);
        if(node->left == nullptr && node->right == nullptr) {
            if(sum == target) {
                vector<int> temp(an);
                ans.push_back(temp);
            }
        }
        else {
            dfs(node->left, an, sum, target, level + 1);
            dfs(node->right, an, sum, target, level + 1);
        }
        an.pop_back();
        sum -= node->val;
        // cout << level << " sum after: " << sum << endl;
    }
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        if(root == nullptr) return ans;
        vector<int> an;
        dfs(root, an, 0, target, 0);
        return ans;
    }
};

int main() {
    
    return 0;
}
