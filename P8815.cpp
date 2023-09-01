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

// 栈顶-当前运算符比较
// 栈顶元素优先级更大，就出栈计算，否则入栈
// 如果优先级相等，运算符出栈
map<pair<char, char>, char> priorer = {{{'(', '&'}, '<'}, {{'(', '|'}, '<'}, {{'(', ')'}, '='}, {{'(', '('}, '<'},
                                 {{'|', '|'}, '>'}, {{'|', ')'}, '>'}, {{'|', '('}, '<'}, {{'|', '&'}, '<'}, {{'|', '#'}, '>'},
                                 {{'&', '|'}, '>'}, {{'&', '&'}, '>'}, {{'&', '('}, '<'}, {{'&', ')'}, '>'}, {{'&', '#'}, '>'},
                                 {{')', '|'}, '>'}, {{')', '&'}, '>'}, {{')', ')'}, '>'}, {{')', '#'}, '>'},
                                 {{'#', '|'}, '<'}, {{'#', '&'}, '<'}, {{'#', '('}, '<'}, {{'#', '#'}, '='}};
stack<char> optr;   // 运算符栈
stack<int> opnd;    // 操作数栈

int caculate(int a, int b, char op) {
    if(op == '&')
        return (a & b);
    else return (a | b);
}

int main() {
    string s;
    cin >> s;
    s.push_back('#');
    int i = 0, len = s.size();
    int and_sc = 0, or_sc = 0;      // 与短路（short circuit）和或短路
    optr.push('#');
    // int opnd_sc = 0, optr_sc;
    int sc = 0;
    char sc_op = '#';
    while(i < len) {
        // printf("idx: %d cur: %c\n", i, s[i]);
        if(s[i] == '1' || s[i] == '0'){  // 数字直接push
            opnd.push(s[i] - '0');
            i ++;
            // printf("OPND push %c\n",s[i]);
        }
        else {  // 运算符
            if(priorer[make_pair(optr.top(), s[i])] == '>') {   // 栈顶运算符优先级大，计算
                int l = opnd.top(); opnd.pop();
                int r = opnd.top(); opnd.pop();
                char op = optr.top();
                if(op == sc_op && sc == optr.size()) sc = 0;
                optr.pop();
                int res = caculate(l, r, op);
                opnd.push(res);
                // printf("caculate %d %c %d, OPND push res: %d\n", l, r, op, res);
            }
            else if(priorer[make_pair(optr.top(), s[i])] == '=') {
                // char ch = optr.top();
                optr.pop();
                i ++;
                // printf("OPTR  pop %c\n", ch);
            }
            else if(priorer[make_pair(optr.top(), s[i])] == '<') {
                optr.push(s[i]);
                i ++;
                // printf("OPTR push %c\n", s[i]);
                if(!optr.empty() && !opnd.empty()) {
                    if(opnd.top() == 0 && optr.top() == '&' && sc == 0) 
                        and_sc ++, sc_op = optr.top(), sc = optr.size();
                    if(opnd.top() == 1 && optr.top() == '|' && sc == 0)
                        or_sc ++, sc_op = optr.top(), sc = optr.size();
                }
            }
        }
    }
    cout << opnd.top() << endl;
    cout << and_sc << ' ' << or_sc << endl;
    return 0;
}
