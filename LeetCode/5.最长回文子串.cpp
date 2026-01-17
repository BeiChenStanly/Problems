/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    string longestPalindrome(string s)
    {
        string t = "^#";
        for (auto c : s)
        {
            t += c;
            t += '#';
        }
        t += '$';
        int len = t.size();
        vector<int> p(len + 1, 0);
        int C = 0, R = 0;
        int ans = 0, center = 0;
        for (int i = 1; i < len - 1; ++i)
        {
            if (R > i)
            {
                p[i] = min(R - i, p[2 * C - i]);
            }
            while (t[i + p[i] + 1] == t[i - p[i] - 1])
            {
                ++p[i];
            }
            if (i + p[i] > R)
            {
                C = i;
                R = i + p[i];
            }
            if (p[i] > ans)
            {
                ans = p[i];
                center = i / 2 - ans / 2 + (i&1) - 1;
            }
        }
        return s.substr(center,ans);
    }
};
// @lc code=end
