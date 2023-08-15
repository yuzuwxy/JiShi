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

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1;

        int max_area = 0, max_i, max_j;
        while(i < j) {
            int area = (j - i) * min(height[j], height[i]);
            if(area > max_area) {
                max_area = area;
                max_i = i;
                max_j = j;
            }
            if(height[i] < height[j]) i ++;
            else j --;
        }
        return max_area;
    }
};

int main() {
    Solution s;
    return 0;
}
