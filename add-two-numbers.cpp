#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int c = 0;  // 进位
        ListNode* l3;
        ListNode* ans = l3;
        
        while(l1 != nullptr || l2 != nullptr) {
            if(l1 == nullptr)
                l1 = new ListNode(0, nullptr);
            if(l2 == nullptr)
                l2 = new ListNode(0, nullptr);

            ListNode* ans_node = new ListNode(0, nullptr);
            ans_node->val = (c + l1->val + l2->val) % 10;
            c = (c + l1->val + l2->val) / 10;
            l3 = ans_node;
            l3 = l3->next;

            l1 = l1->next;
            l2 = l2->next;
        }

        if(c != 0) {
            l3 = new ListNode(0, nullptr);
            l3->val = c;
        }
        return ans;
    }
};