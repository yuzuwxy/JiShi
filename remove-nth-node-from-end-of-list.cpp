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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p, *q, *pre;
        pre = head;
        p = head->next, q = head->next;
        while(q != nullptr && n != 0) {
            q = q->next;
            n --;
        }
        while(q != nullptr) {
            q = q->next;
            pre = p;
            p = p->next;
        }
        pre->next = p->next;
        delete p;

        return head;
    }
};

int main() {
    
    return 0;
}
