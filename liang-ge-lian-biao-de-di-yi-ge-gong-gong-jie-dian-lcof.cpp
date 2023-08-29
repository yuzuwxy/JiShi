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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *A = new ListNode(0), *B = new ListNode(0);
        A->next = headA, B->next = headB;
        ListNode *p = A->next;
        int num_A = 0;
        while(p != nullptr) {
            num_A ++;
            p = p->next;
        }
        p = B->next;
        int num_B = 0;
        while(p != nullptr) {
            num_B ++;
            p = p->next;
        }
        // 右端对齐
        int k = abs(num_B - num_A);
        ListNode *shorter = (num_B <= num_A) ? B->next : A->next;
        ListNode *longer = (num_B > num_A) ? B->next : A->next;
        while(k != 0) {
            k --;
            longer = longer->next;
        }
        
        ListNode *ans = nullptr;
        while(longer != nullptr && shorter != nullptr) {
            if(longer->val == shorter->val) {
                ans = longer;
                break;
            }
            longer = longer->next;
            shorter = shorter->next;            
        }
        return ans;
    }
};

int main() {
    
    return 0;
}
