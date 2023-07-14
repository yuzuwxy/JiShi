#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        int s_len = s.size();
        int word_num = words.size();
        int word_len = words[0].size();

        for(int i = 0; i < word_len; i ++) {
            int win_l = i, win_r = i + word_num * word_len;

            if(win_r > s_len) break;
            map<string, int> diff;

            for(string word : words) {
            // for(int j = win_l; j < win_r; j += word_len){
                // 注意C++的substring第二个参数是希望截取的子串的长度
                // string word = s.substr(j, word_len);
                if(diff.count(word) == 0) diff[word] = 1;
                else diff[word] ++;
            }

            // 查看单词列表中的每个单词是不是出现在窗口中
            for(int j = win_l; j < win_r; j += word_len){
            // for(string word : words) {  // 你这跟Java有什么区别。。感觉塌房了
                string word = s.substr(j, word_len);
                if(diff.count(word) != 0) {
                    diff[word] --;
                    if(diff[word] == 0)
                        diff.erase(word);
                }
                else{
                    diff[word] = 0;
                    diff[word] --;
                }
            }
            if(diff.empty()) 
                res.push_back(win_l);

            // cout << win_l << endl;
            // map<string, int>::iterator it;
            // for(it = diff.begin(); it != diff.end(); it ++)
            //     cout << it->first << ' ' << it->second << endl;

            // 开始滑动窗口
            // while(win_l <= s_len - word_num * (word_len + 1)) {
            while(win_r + word_len <= s_len) {
                // 去掉左边的单词
                string left_word = s.substr(win_l, word_len);
                win_l += word_len;
                if(diff.count(left_word) != 0) {
                    diff[left_word] ++;
                    if(diff[left_word] == 0)
                        diff.erase(left_word);
                }
                else diff[left_word] = 1;
                
                // 右边的单词
                string right_word = s.substr(win_r, word_len);
                win_r += word_len;
                // if(diff.count(right_word) == 0) diff[right_word] = 1;
                // else diff[right_word] ++;
                if(find(words.begin(), words.end(), right_word) != words.end()) {
                    diff[right_word] --;
                    if(diff[right_word] == 0)
                        diff.erase(right_word);
                }
                else {
                    if(diff.count(right_word) == 0) diff[right_word] = -1;
                    else diff[right_word] --;
                }
                
                if(diff.empty())
                    res.push_back(win_l);

                // cout << win_l << endl;
                // for(it = diff.begin(); it != diff.end(); it ++)
                //     cout << it->first << ' ' << it->second << endl;
            }
        }


        return res;
    }
};