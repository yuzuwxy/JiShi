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
#include<stack>

#define MAXN (int)1e5
#define ll long long

using namespace std;

typedef struct ListNode{
    int num = 0;
    ListNode* next = nullptr;
}ListNode, *LinkList;

int main() {
    int n;
    while(cin >> n) {
        if(n == 0) return 0;
        
        vector<LinkList> v(n + 1, new ListNode); // 存图
        for(int i = 1; i <= n; i ++) {
            v[i] = new ListNode;        // 关键是这句（但是不太知道为啥）
            int node;
            for(int j = 1; j <= 3; j++) {
                cin >> node;
                if(node != 0) {
                    ListNode *p = new ListNode;
                    p->num = node, p->next = v[i]->next;
                    v[i]->next = p;
                }
            }
        }
        int m;
        cin >> m;
        stack<int> s;
        int idx;
        s.push(1);      // 站在第一个路口
        while(!s.empty()) {
            idx = s.top();
            s.pop();
            if(idx == m) break;
            ListNode *p = v[idx]->next;
            while(p!=nullptr){
                s.push(p->num);
                p = p->next;
            }
        }
        if(idx == m) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
