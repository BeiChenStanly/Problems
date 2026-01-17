
/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        if(x%10==0){
            if(x == 0) return true;
            return false;
        }
        long long reversed = 0;
        int xx = x;
        while(xx){
            reversed = reversed * 10 + xx%10;
            xx /= 10;
        }
        return reversed == x;
    }
};
// @lc code=end

