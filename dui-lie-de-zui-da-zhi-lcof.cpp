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

class MaxQueue {
private:
    int q[10000] = {0};
    int max_q[10000] = {0};
    int q_head = 0, q_tail = 0;
    int max_head = 0, max_tail = 0;
public:
    MaxQueue() {}
    
    int max_value() {
        if(max_head == max_tail) return -1;
        else return q[max_q[max_head]];
    }
    
    void push_back(int value) {
        if(q_head == q_tail) {  // 队列为空
            max_q[max_tail ++] = q_tail;
        }
        else {
            while(max_head != max_tail) {
                if(q[max_q[max_tail]] < value) max_tail --;
                else break;
            } 
            max_q[max_tail ++] = q_tail;
        }
        q[q_tail ++] = value;
    }
    
    int pop_front() {
        if(q_head == q_tail) return -1;
        int q_front = q[q_head];
        if(max_q[max_head] == q_head) max_head ++;
        q_head ++;
        return q_front;
    }
};


int main() {
    
    return 0;
}
