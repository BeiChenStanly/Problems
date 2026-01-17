/*
 * @lc app=leetcode.cn id=12 lang=cpp
 *
 * [12] 整数转罗马数字
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
vector<string> SYMBOLS = {"I","V","X","L","C","D","M"};
int pows[] = {1,10,100,1000};
class Solution {
public:
    string digitToRoman(int digit, int p){
        if(digit == 4) return SYMBOLS[p*2]+SYMBOLS[p*2+1];
        if(digit == 9) return SYMBOLS[p*2]+SYMBOLS[p*2+2];
        string ans;
        if(digit >= 5) ans += SYMBOLS[p*2+1], digit-=5;
        while(digit>0){
            ans+=SYMBOLS[p*2];
            digit--;
        }
        return ans;
    }
    string intToRoman(int num) {
        string ans = "";
        for(int i = 3; i >= 0; i--){
            int digit = num / pows[i] % 10;
            ans += digitToRoman(digit,i);
        }
        return ans;
    }
};
// @lc code=end

