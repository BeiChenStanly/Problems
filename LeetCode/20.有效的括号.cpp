/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        for (char c : s)
        {
            if (c == '(' || c == '{' || c == '[')
                st.push(c);
            else
            {
                if (st.empty())
                    return false;
                char t = st.top();
                st.pop();
                bool b;
                switch (t)
                {
                case '(':
                    b = c == ')';
                    break;
                case '{':
                    b = c == '}';
                    break;
                case '[':
                    b = c == ']';
                    break;
                default:
                    break;
                }
                if (!b)
                    return false;
            }
        }
        return st.empty();
    }
};
// @lc code=end
