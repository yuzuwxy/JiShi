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

    bool isMatch(TreeNode* A, TreeNode* B) {
        if(B == nullptr) return true;
        if(A == nullptr) return false;
        if(A->val != B->val) return false;

        return isMatch(A->left, B->left) && isMatch(A->right, B->right);
    }
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(A == nullptr || B == nullptr) {
            return false;
        }
        
        return isMatch(A, B) || isSubStructure(A->right, B) || isSubStructure(A->left, B);
    }
};

int main() {
    
    return 0;
}
