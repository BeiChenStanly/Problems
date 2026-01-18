/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 23001;
        vector<int> lens(2001);
        for(int i = 0; i < nums.size(); i++)
            lens[nums[i]+1000]++;
        for (int i = 0; i < nums.size(); i+=lens[nums[i]+1000])
        {
            for (int j = i + 1, k = nums.size() - 1; j < k;)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if (abs(sum - target) < abs(ans - target))
                    ans = sum;
                if (sum == target)
                    return sum;
                else if (sum > target){
                    k -= lens[nums[k]+1000];
                }
                else{
                    j += lens[nums[j]+1000];
                }
            }
        }
        return ans;
    }
};
// @lc code=end

