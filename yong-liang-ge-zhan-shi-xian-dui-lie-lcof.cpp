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

class CQueue {
private:    
    stack<int> A, B;
public:
    CQueue() {
    }
    
    void appendTail(int value) {
        A.push(value);
    }
    
    int deleteHead() {
        int ans = 0;
        if(!B.empty()) {
            ans = B.top();
            B.pop();
        }
        else if(A.empty()) ans = -1;
        else if(!A.empty()) {
            while(!A.empty()) {
                B.push(A.top());
                A.pop();
            }
            ans = B.top();
            B.pop();
        }
        return ans;
    }
};

// class CQueue {
// private:
//     int head = 0, tail = 0;
//     int q[10000] = {0};
// public:
//     CQueue() {
//     }
    
//     void appendTail(int value) {
//         q[tail] = value;
//         tail = (tail + 1) % 10000;
//     }
    
//     int deleteHead() {
//         int val = 0;
//         if(head == tail) val = -1;
//         else {
//             val = q[head];
//             head = (head + 1) % 10000;
//         }
//         return val;
//     }
// };

int main() {
    
    return 0;
}
