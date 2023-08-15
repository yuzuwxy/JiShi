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

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *L1, *L2;
        L1->next = list1, L2->next = list2; // 加个头结点更好处理

        ListNode *p1, *p2, *p;
        p1 = L1->next, p2 = L2->next;
        p = L1;

        while(p1 != nullptr && p2 !=nullptr) {
            if(p1->val <= p2->val) {
                p->next = p1;
                p1 = p1->next;
            }
            else {
                p->next = p2;
                p2 = p2->next;
            }
            p = p->next;
        }

        p->next = (p1 == nullptr) ? p2 : p1;

        return L1->next;
    }
};

int main() {
    
    return 0;
}
