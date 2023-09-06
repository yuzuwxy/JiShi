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

class Solution {
public:
    int minArray(vector<int>& numbers) {
        int len = numbers.size();
        int l = 0, r = len - 1;

        while(l < r) {
            int mid = (l + r) >> 1;
            if(numbers[mid] > numbers[r])
                l = mid + 1;
            else if(numbers[mid] < numbers[r])
                r = mid;
            else if(numbers[mid] == numbers[r])
                r --;
            else if(numbers[mid] == numbers[l])
                l ++;
        }
        return numbers[l];        
    }
};

// class Solution {
// public:
//     int minArray(vector<int>& numbers) {
//         int minn = numbers[0];
//         int len = numbers.size();
//         for(int i = 0; i < len; i ++) 
//             minn = min(minn, numbers[i]);
//         return minn;        
//     }
// };


int main() {
    
    return 0;
}
