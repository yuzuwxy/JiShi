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

const int ele_num = 5;
int main() {
    int T;
    cin >> T;
    while(T --) {
        int status[5][2];
        int target = 0;
        for(int i = 0; i < ele_num; i ++)
            cin >> status[i][0] >> status[i][1];
        cin >> target;

        int ans_time = 1000;
        int ans = 0;
        for(int i = 0; i < ele_num; i ++) {
            if(target == 15 && i <= 2) continue;    // 前3号到达不了第15层
            if(target % 2 == 0 && i == 4) continue; // 5号只在单数号停靠
            int time = 0;
            // 方向：向下移动是-1，静止为0，向上移动为1
            int ele_dir = (status[i][0] > status[i][1]) ? -1 : ((status[i][0] == status[i][1]) ? 0 : 1);
            int my_dir = (target > 1) ? 1 : ((target == 1) ? 0 : -1);

            if(ele_dir == 0) {  // 电梯静止：直接从静止层移到一层，然后移动到目标层
                int time_to_1 = ((status[i][0] < 0) ? (- status[i][0]) : (status[i][0] - 1)) * 2;
                int time_to_t = ((target < 0) ? (- target) : (target - 1)) * 2;      // time_to_target
                time = time_to_1 + time_to_t;
            }
            else if((((status[i][0] > 1) && (status[i][1] < 1) && my_dir == -1) || ((status[i][0] < 1) && (status[i][1] > 1) && my_dir == 1))) { 
                int time_to_1 = ((status[i][0] < 0) ? (- status[i][0]) : (status[i][0] - 1)) * 2;
                int time_to_t = ((target < 0) ? (- target) : (target - 1)) * 2;
                time = time_to_1 + time_to_t;
            }
            else {
                // 电梯完成移动路线
                int time_ele = ((status[i][0] * status[i][1] > 0) ? (abs(status[i][0] - status[i][1])) : (abs(status[i][0] - status[i][1]) - 1) ) * 2;
                int time_to_1 = ((status[i][1] < 0) ? (- status[i][1]) : (status[i][1] - 1)) * 2;
                int time_to_t = ((target < 0) ? (- target) : (target - 1)) * 2;
                time = time_ele + time_to_1 + time_to_t;
            }
            if(ans_time > time) {
                ans_time = min(ans_time, time);
                ans = i + 1;
            }
        }
        cout << /* "ans_time: " << ans_time << " ans: " <<  */ans << endl;
    }
    return 0;
}
