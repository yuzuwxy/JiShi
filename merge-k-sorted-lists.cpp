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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if(k == 0) return (ListNode*)nullptr;

        ListNode *L = new ListNode;
        L->next = lists[0];
        for(int i = 1; i < k; i ++) {
            ListNode *p1 = L->next;
            ListNode* p2 = lists[i];
            ListNode *p;
            while(p1 != nullptr && p2 != nullptr) {
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
        }
        return L->next;
    }
};

int main() {
    
    return 0;
}



