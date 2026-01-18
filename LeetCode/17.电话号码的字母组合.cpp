/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
unordered_map<char,vector<string>> c2s = {{'2',{"a","b","c"}},{'3',{"d","e","f"}},{'4',{"g","h","i"}},{'5',{"j","k","l"}},{'6',{"m","n","o"}},{'7',{"p","q","r","s"}},{'8',{"t","u","v"}},{'9',{"w","x","y","z"}}};
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        return dfs(digits,digits.size()-1);
    }
    vector<string> dfs(const string& digits,int i){
        vector<string> ret;
        if(i==0){
            return c2s[digits[i]];
        }
        else{
            auto res = dfs(digits,i-1);
            for(auto c:c2s[digits[i]])
                for(auto s:res)
                    ret.push_back(s+c);
            return ret;
        }
    }
};
// @lc code=end
