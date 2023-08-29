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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *L1 = new ListNode(0), *L2 = new ListNode(0);
        L1->next = l1, L2->next = l2;
        ListNode *p = L1->next, *q = L2->next;
        ListNode *ans = L1;

        while(p != nullptr && q != nullptr) {
            if(p->val <= q->val) {
                ans->next = p;
                p = p->next;
            }
            else {
                ans->next = q;
                q = q->next;
            }
            ans = ans->next;
        }
        ans->next = (p == nullptr) ? q : p;
        return L1->next;
    }

};

int main() {
    
    return 0;
}
