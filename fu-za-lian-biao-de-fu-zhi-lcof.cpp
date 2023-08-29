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

#define MAXN (int)1e5
#define ll long long

using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    // 旧结点和新结点的映射
    map<Node*, Node*> m;
    Node* copyRandomList(Node* head) {
        if(head == nullptr) 
            return nullptr;
        
        if(m.count(head) == 0) {
            Node *newhead = new Node(head->val);
            m[head] = newhead;
            newhead->next = copyRandomList(head->next);
            newhead->random = copyRandomList(head->random);
        }
        return m[head];
    }
};

int main() {
    
    return 0;
}
