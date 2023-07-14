#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>

#define NO() {cout << "NO\n"; return;}
#define YES() {cout << "YES\n"; return;}

#define ELE_NUM 5
#define INIT_FLOOR 1

using namespace std;

// 计算某个电梯从curr_ele层到target层需要的时间
int caculate(int curr_ele, int target) {
    // 比如 -1 到 1其实只有1层但是差是2， 如果都是地上层或都是地下层，直接相减即可
    if(curr_ele * target < 0) {
        return (abs(curr_ele - target) - 1) * 2;
    }
    else return (abs(curr_ele - target)) * 2;
}

void process() {
    int elevators[7][5] = {0};
    int target; 

    // 电梯状态
    for(int i = 1; i <= ELE_NUM; i ++) 
        cin >> elevators[i][1] >> elevators[i][2];
    // 目标楼层
    cin >> target;

    int ans = 0;
    int min_time = 100;
    for(int i = 1; i <= ELE_NUM; i ++) {
        // 1,2,3号电梯只能到达B4-14F
        if(i <= 3 && (target > 14)) continue;
        // 5号电梯只在单数层停靠
        if(i == 5 && target % 2 == 0) continue;

        int t = 72;
        // 电梯静止，即(elevators[i][2] - elevators[i][1]) * (target - INIT_FLOOR) == 0
        if(elevators[i][1] == elevators[i][2]) {
            // 先从停靠层到1F，再从1F到目标层
            t = caculate(elevators[i][1], INIT_FLOOR) + caculate(INIT_FLOOR, target);
            // cout << "case 1: " << t << endl;
        }
        // 移动方向相同
        else if(((elevators[i][2] - elevators[i][1]) * (target - INIT_FLOOR) > 0) && (INIT_FLOOR > elevators[i][1] && INIT_FLOOR < elevators[i][2])){
            // 经过用户所在楼层（即1F）
            t = caculate(elevators[i][1], INIT_FLOOR) + caculate(INIT_FLOOR, target);
        }
        // 移动方向不同
        else {
            // 电梯完成自己的移动路线，再从完成时停靠的楼层到达1层再到达用户目标楼层
            t = caculate(elevators[i][1], elevators[i][2]) + caculate(elevators[i][2], INIT_FLOOR) + caculate(INIT_FLOOR, target);
            // cout << "case 3: " << t << endl;
        }
        if(t < min_time) ans = i, min_time = t;
        // cout << t << endl;
    }
    cout << ans << endl;
    return;
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        process();
    }
}