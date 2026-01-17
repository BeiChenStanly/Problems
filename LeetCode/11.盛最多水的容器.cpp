/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int l = 0,r = height.size() - 1;
        while(l < r){
            ans = max(ans,(r-l)*min(height[l],height[r]));
            if(height[l] < height[r]){
                l++;
            }
            else{
                r--;
            }
        }
        return ans;
    }
};
// @lc code=end

