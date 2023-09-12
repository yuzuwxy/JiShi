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

/* //冒泡. O(n^2), 时间超限 
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> ans(0, k);

        int len = arr.size();
        if(len == k) return arr;
        for(int i = 0; i < k; i ++) {
            int count = 0;
            for(int j = 1; j < len - i; j ++) {
                if(arr[j] > arr[j - 1]) {
                    int temp = arr[j - 1];
                    arr[j - 1] = arr[j];
                    arr[j] = temp;
                    count ++;
                }
            }
            if(count == 0) break;
        }
        ans.resize(k);
        copy(arr.begin() + (len - k), arr.end(), ans.begin());
        return ans;
    }
}; */

/* // STL快排
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> ans(0, k);

        int len = arr.size();
        sort(arr.begin(), arr.end());
        ans.resize(k);
        copy(arr.begin(), arr.begin() + k, ans.begin());
        return ans;
    }
}; */

/* // 归并排序
class Solution {
public:
    vector<int> temp;
    void partition(vector<int>& arr, int l, int r) {
        if(l >= r) return;

        int mid = (l + ((r - l) >> 1));
        partition(arr, l, mid);
        partition(arr, mid + 1, r);
        temp.clear();

        int i = l, j = mid + 1;
        while(i <= mid && j <= r) {
            if(arr[i] < arr[j]) {
                temp.push_back(arr[i]);
                i ++;
            }
            else {
                temp.push_back(arr[j]);
                j ++;
            }
        }
        for(int k = i; k <= mid; k ++)
            temp.push_back(arr[i]);
        for(int k = j; k <= r; k ++)
            temp.push_back(arr[i]);
        copy(temp.begin(), temp.end(), arr.begin() + l);
        return;
    }
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        int len = arr.size();
        partition(arr, 0, len - 1);
        vector<int> ans(arr.begin(), arr.begin() + k);
        return ans;
    }
}; */

// 快排更好一点，直接可以找到前k个，不需要全部排序。
class Solution {
public:

    int partition(vector<int>& arr, int l, int r) {
        int pivoval = arr[l];
        while(l < r) {
            while(l < r && arr[r] >= pivoval) r --;
            arr[l] = arr[r];
            while(l < r && arr[l] <= pivoval) l ++;
            arr[r] = arr[l];
        }
        arr[l] = pivoval;
        return r;
    }
    void quit_sort(vector<int>& arr, int l, int r, int k) {
        // cout << "l: " << l << " r: " << r << endl; 
        if(l < r) {
            int pivoloc = partition(arr, l, r);
            // cout << "val: " << arr[pivoloc] << " loc: " << pivoloc << endl;
            // for(int i = 0; i < arr.size(); i ++)
            //     cout << arr[i] <<  ' ';
            // cout << endl;
            if(pivoloc >= k)
                quit_sort(arr, l, pivoloc - 1, k);
            else
                quit_sort(arr, pivoloc + 1, r, k);
            if(pivoloc == k - 1)
                return;
        }
    }
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        int len = arr.size();
        quit_sort(arr, 0, len - 1, k);

        vector<int> ans(arr.begin(), arr.begin() + k);
        return ans;
    }
};

// 堆排？堆排还是有点超前了，需要一直调整树
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

// class Solution {
// public:
//     vector<int> getLeastNumbers(vector<int>& arr, int k) {
//     }
// };

int main() {
    
    return 0;
}
