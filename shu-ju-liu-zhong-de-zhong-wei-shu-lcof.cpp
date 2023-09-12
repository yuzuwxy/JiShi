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

/* class MedianFinder {
public:
    priority_queue<double, vector<double>, less<double>> minn; // 小于等于中位数的数，降序，最大值在队头
    priority_queue<double, vector<double>, greater<double>> maxx; // 大于中位数的数，升序，小值在队头
    double midd = 0;
    int min_len = 0;
    int max_len = 0;

    MedianFinder() { }
    
    void addNum(int num) {
        if(min_len == 0) {
            minn.push(num);
            min_len ++;
        }
        else {
            if(num > midd) {    // 大于中位数的加入maxx队列
                maxx.push(num);
                max_len ++;
            }
            else {
                minn.push(num);
                min_len ++;
            }
        }
        if(min_len > max_len) {
            while(min_len - max_len > 1) {
                double temp = minn.top();
                minn.pop(); min_len --;
                maxx.push(temp); max_len ++;
            }
        }
        else if(max_len > min_len) {
            while(min_len - max_len < 0) {
                int temp = maxx.top();
                maxx.pop(); max_len --;
                minn.push(temp); min_len ++;
            }
        }
        if(min_len == max_len) midd = ((minn.top() + maxx.top())) / 2.0;
        else if(min_len - max_len == 1) midd = minn.top();
    }
    
    double findMedian() {
        return midd;
    }
}; */

/* class MedianFinder {
public:
    priority_queue<double, vector<double>, less<double>> minn; // 小于等于中位数的数，降序，最大值在队头
    priority_queue<double, vector<double>, greater<double>> maxx; // 大于中位数的数，升序，小值在队头

    MedianFinder() { }
    
    void addNum(int num) {
        if(minn.empty() || num <= minn.top()){
            minn.push(num);
            if(minn.size() - maxx.size() > 1) {
                maxx.push(minn.top());
                minn.pop();
            }
        }
        else if(num > minn.top()) {
            maxx.push(num);
            if(maxx.size() > minn.size()) {
                minn.push(maxx.top());
                maxx.pop();
            }
        }
    }
    
    double findMedian() {
        if(minn.size() > maxx.size()) 
            return (minn.top() + maxx.top()) / 2.0;
        else return minn.top();
    }
}; */

class MedianFinder {
public:
    multiset<double> nums;
    multiset<double>::iterator left, right;

    MedianFinder() { }
    
    void addNum(int num) {
        if(nums.empty()) {
            nums.insert(num);
            left = nums.begin();
            right = nums.begin();
        }
        else {
            nums.insert(num);
            if(right == left) {
                if(num >= *left) 
                    right ++;
                else 
                    left --;
            }
            else {
                if(num >= *right)
                    left ++;
                else if(num >= *left) 
                    right --, left ++;
                else right --;
            }
        }
    }
    
    double findMedian() {
        return (*left + *right) / 2.0;
    }
};

int main() {
    
    return 0;
}
