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
    ListNode* reverseList(ListNode* head) {
        ListNode *L = new ListNode(0);

        ListNode *p = head;
        while(p != nullptr) {
            ListNode *q = p->next;
            p->next = L->next;
            L->next = p;
            p = q;
        }

        return L->next;
    }
};

int main() {
    
    return 0;
}
