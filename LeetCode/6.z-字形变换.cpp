/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        vector<string> layers(numRows);
        int lay = 0;
        int state = -1;
        for(auto c : s){
            layers[lay].push_back(c);
            if(lay == numRows - 1 || lay == 0) state = -state;
            lay += state;
        }
        string ans;
        for (const string &layer : layers)
            ans += layer;
        return ans;
    }
};
// @lc code=end
