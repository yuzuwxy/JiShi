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
    void recursion(vector<int> &ans, ListNode *p){
        if(p == nullptr) return;

        recursion(ans, p->next);
        ans.push_back(p->val);
    }
    vector<int> reversePrint(ListNode* head) {
        ListNode* p = head;
        vector<int> ans;
        
        recursion(ans, p);

        return ans;
    }
};

int main() {
    
    return 0;
}
