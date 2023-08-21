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
    ListNode* swapPairs(ListNode* head) {
        ListNode *L = new ListNode;
        L->next = head;
        ListNode *pre = L, *p = L->next;
        if(p == nullptr) return head;
        int i = 1;
        while(p->next != nullptr) {
            ListNode *q = p->next;
            pre->next = q;
            p->next = q->next;
            q->next = p;

            pre = p;
            p = p->next;
            if(p == nullptr) break;
        }
        return L->next;
    }
};

int main() {
    
    return 0;
}
