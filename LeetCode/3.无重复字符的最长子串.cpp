/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==1) return 1;
        int pre[128];
        for(int i = 0; i < 128; i++){
            pre[i] = -1;
        }
        int ans = 0;
        int l=0,r=0;
        for(; r < s.size(); r++){
            if(l<=pre[(int)s[r]]){
                ans = max(ans,r-l);//[l,r-1]
                l = pre[(int)s[r]] + 1;
            }
            pre[(int)s[r]] = r;
        }
        ans = max(ans,r - l);
        return ans;
    }
};
// @lc code=end
