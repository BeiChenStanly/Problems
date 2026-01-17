/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(),m = p.size();
        vector<vector<bool>> dp(n + 1,vector<bool>(m + 1,0));
        dp[0][0] = 1;
        for(int i = 0; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j] || dp[i][j - 2];
                    if (i != 0 &&(p[j - 2] == '.'||s[i - 1] == p[j - 2])) {
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                    }
                }
                else {
                    if (i != 0 &&(p[j - 1] == '.'||s[i - 1] == p[j - 1])) {
                        dp[i][j] = dp[i][j] || dp[i - 1][j - 1];
                    }
                }
            }
        }
        return dp[n][m];
    }
};
// @lc code=end
