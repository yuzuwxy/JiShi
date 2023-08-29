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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode *L = new ListNode(0);
        L->next = head;
        ListNode *p = L->next, *q = L;
        int count = 0;
        while(p != nullptr) {
            if(count == k) q = q->next;
            p = p->next;
        }
        return q;
    }
};

int main() {
    
    return 0;
}
