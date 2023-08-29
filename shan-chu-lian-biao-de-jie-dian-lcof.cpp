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

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode *L = new ListNode(0);
        L->next = head;
        ListNode *p = L->next, *pre = L;

        while(p != nullptr) {
            if(p->val == val) {
                ListNode *temp = p;
                p = p->next;
                pre->next = p;
                // 不需要我自己delete， ok
                // delete temp;
            }
            else {
                pre = p;
                p = p->next;
            }
        }
        return L->next;
    }
};

int main() {
    
    return 0;
}
