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
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n == 0) return 0;
        int maxLen = 0;
        vector<char> subS;
        for(int i = 0; i < n; i ++)  {
            while(find(subS.begin(), subS.end(), s[i]) != subS.end())
                subS.erase(subS.begin());
            subS.push_back(s[i]);
            maxLen = max(maxLen, (int)(subS.size()));
        }
        return maxLen;
    }
};