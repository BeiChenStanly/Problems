/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        int minn = 201;
        for (int i = 0; i < strs.size(); i++)
            minn = min(minn, (int)strs[i].size());
        for (int j = 0; j < minn; j++)
        {
            char c = strs[0][j];
            for (int i = 1; i < strs.size(); i++)
                if (strs[i][j] != c)
                    return strs[0].substr(0, j);
        }
        return strs[0].substr(0, minn);
    }
};
// @lc code=end
