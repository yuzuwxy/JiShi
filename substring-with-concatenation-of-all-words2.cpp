// 第二遍做
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
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        int words_size = words.size();
        int len_p = words[0].size();
        int len_s = s.size();
        if(words_size == 0) return ans;
        if(len_s < len_p) return ans;
        if(words_size * len_p > len_s) return ans;

        for(int i = 0; i < len_p; i ++) {
            // 要容纳所有的单词，窗口的长度就是所有单词的长度
            int win_l = i, win_len = words_size * len_p;
            if(win_l + win_len > len_s) break;

            map<string, int> m;
            for(int i = 0; i < words_size; i ++) {
                if(m.count(words[i]) != 0) m[words[i]] ++;
                else m[words[i]] = 1;
            }
            for(int j = win_l; j < win_l + win_len; j += len_p) {
                string word = s.substr(j, len_p);
                if(m.count(word) != 0){
                    m[word] --;
                    if(m[word] == 0) m.erase(word);
                }
                else m[word] = -1;
            }
            if(m.empty()) ans.push_back(win_l);
            win_l += len_p;
            while(win_l <= len_s - win_len) {
                int win_r = win_l + win_len;
                string word = s.substr(win_l - len_p, len_p);
                if(m.count(word) != 0) {
                    m[word] ++;
                    if(m[word] == 0) m.erase(word);
                }
                else m[word] = 1;
                word = s.substr(win_r - len_p, len_p);
                if(m.count(word) != 0) {
                    m[word] --;
                    if(m[word] == 0) m.erase(word);
                }
                else m[word] = -1;
                if(m.empty()) ans.push_back(win_l);
                win_l += len_p;
            }
        }
        return ans;
    }
};

int main() {
    
    return 0;
}
