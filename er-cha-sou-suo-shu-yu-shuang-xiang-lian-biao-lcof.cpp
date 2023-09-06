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


// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
private:
    Node *head;
    Node *pre;

public:
    Node* treeToDoublyList(Node* root) {
        if(root == nullptr) return root;

        dfs(root);

        head->left = pre;
        pre->right = head;

        return head;
    }

    void dfs(Node *node) {
        if(node == nullptr) return;

        dfs(node->left);

        if(pre == nullptr) 
            head = node;
        else pre->right = node;
        node->left = pre;
        pre = node;

        dfs(node->right);

    }
};

int main() {
    
    return 0;
}
