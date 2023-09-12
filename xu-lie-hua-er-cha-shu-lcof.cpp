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

class Codec {
public:
    // 前序遍历
    void preOrder(TreeNode* node, string &pre_s) {
        if(node == nullptr) {
            pre_s += "none,";
            return;
        }
        pre_s += to_string(node->val) + ",";
        preOrder(node->left, pre_s);
        preOrder(node->right, pre_s);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string pre_s;
        preOrder(root, pre_s);
        // cout << pre_s << endl;
        return pre_s;
    }

    // 根据前序遍历建树
    TreeNode* prebuild(vector<string>& preorder, int& i) {
        // cout << preorder[i] << endl;


        if(preorder[i] == "none") {
            i ++;
            return nullptr;
        }

        TreeNode* root = new TreeNode(stoi(preorder[i ++]));
        root->left = prebuild(preorder, i);
        root->right = prebuild(preorder, i);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int len = data.size();
        vector<string> preorder;
        int i = 0;
        string str  ="";
        while(i < len) {
            // cout << data[i];
            if(data[i] == ',') {
                preorder.push_back(str);
                str.clear();
                i ++;
                continue;
            }
            str.push_back(data[i]);
            i ++;
        }
        if(str != "")
            preorder.push_back(str);
        // cout << str << endl;
        // 根据前序遍历建树
        TreeNode* root;
        i = 0;
        return prebuild(preorder, i);;
    }
};

int main() {
    
    return 0;
}
