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
#include<set>

#define MAXN (int)1e5
#define ll long long

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    int tree[6000] = {0, 0};
    int ser_nums = (1 << N);    // 服务结点的个数
    int node_nums = (1 << (N + 1)) - 1; // 树结点的个数
    // cout << ser_nums << ' ' << node_nums << endl;
    int aver = Q / ser_nums;
    int other = Q % ser_nums;

    for(int i = 0; i < other; i ++) {
        int node = 1;
        while(node <= node_nums) {
            tree[node] ++;
            // cout << "node: " << node << " val: " << tree[node] << endl;
            int l = node * 2, r = node * 2 + 1;
            if(tree[l] == tree[r]) {
                node = l;
            }
            else if(tree[l] > tree[r]) {
                node = r;
            }
        }
    }
    vector<int> ans;
    for(int i = ser_nums; i <= node_nums; i ++){
        ans.push_back(tree[i] + aver);
    }
    
    for(int i = 0; i < ser_nums; i ++)
        cout << ans[i] << ' ';
    cout << endl;
    return 0;
}
