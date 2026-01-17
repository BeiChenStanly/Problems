/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int myAtoi(string s) {
        long long ans = 0;
        int flag = 1;
        int i = 0;
        while(s[i] == ' ')i++;
        if(s[i]=='-' || s[i]== '+'){
            flag = s[i]=='-'?-1:1;
            i++;
        }
        for(;i < s.size(); i++){
            if(!isdigit(s[i]))return flag * ans;
            ans = ans * 10 + s[i] - '0';
            if(flag * ans < INT32_MIN) return INT32_MIN;
            if(flag * ans > INT32_MAX) return INT32_MAX;
        }
        return flag * ans;
    }
};
// @lc code=end

