/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
unordered_map<char,int> NUMS = {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        for(int i = 0; i < s.size();i++){
            if(i != s.size() - 1 && NUMS[s[i + 1]] > NUMS[s[i]]){
                ans += NUMS[s[i + 1]] - NUMS[s[i]];
                i++;
            }
            else{
                ans += NUMS[s[i]];
            }
        }
        return ans;
    }
};
// @lc code=end
