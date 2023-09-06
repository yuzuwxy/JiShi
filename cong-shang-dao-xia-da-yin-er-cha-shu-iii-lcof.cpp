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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        deque<TreeNode*> dq;
        int level = 1;
        if(root == nullptr) return ans;
        dq.push_back(root);

        while(!dq.empty()) {
            vector<int> ret;
            int level_num = dq.size();
            for(int i = 0; i < level_num; i ++) {
                TreeNode *t;
                if(level % 2 == 0) {
                    t = dq.front(); dq.pop_front();
                    ret.push_back(t->val);
                    if(t->right != nullptr) dq.push_back(t->right);
                    if(t->left != nullptr) dq.push_back(t->left);
                } 
                else {
                    t = dq.back(); dq.pop_back();
                    ret.push_back(t->val);
                    if(t->left != nullptr) dq.push_front(t->left);
                    if(t->right != nullptr) dq.push_front(t->right);
                }
            }
            ans.push_back(ret);
            level ++;
        }
        return ans;
    }
};

int main() {
    
    return 0;
}
