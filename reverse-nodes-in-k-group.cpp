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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *p, *pre, *q, *L, *ans;
        L = new ListNode; L->next = head;
        ans = L;
        if(head == nullptr) return head;

        p = L->next, pre = L, q = L->next;
        int count = 1;
        while(p != nullptr && q != nullptr) {
            if(count % k == 0) {
                ListNode *ans_ = p;
                q = q->next;
                while(p != q) {
                    ListNode *nxt = p->next;
                    p->next = ans->next;
                    ans->next = p;
                    p = nxt;
                }
                p = q;
                ans = ans_;
                count = 1;
            }
            else {
                q = q->next;
                count ++;
            }
        }
        ans->next = p;
        return L->next;
    }
};

int main() {
    
    return 0;
}
