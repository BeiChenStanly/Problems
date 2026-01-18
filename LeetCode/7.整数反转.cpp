/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int reverse(int x) {
        int flag = 1;
        long long xx = x;
        if(xx < 0){
            xx = -xx;
            flag = -1;
        }
        long long ans = 0;
        while(xx){
            ans = ans * 10 + xx%10;
            xx /= 10;
        }
        ans *= flag;
        if(ans < INT32_MIN || ans > INT32_MAX) return 0;
        return ans;
    }
};
// @lc code=end
