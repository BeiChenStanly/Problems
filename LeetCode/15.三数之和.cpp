/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; ++i)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1, k = nums.size() - 1; j < k;)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0)
                {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    int k0 = k - 1;
                    while (j < k0 && nums[k0] == nums[k])
                        --k0;
                    k = k0;
                    int j0 = j + 1;
                    while (j0 < k && nums[j0] == nums[j])
                        ++j0;
                    j = j0;
                }
                else if (sum > 0)
                {
                    int k0 = k - 1;
                    while (j < k0 && nums[k0] == nums[k])
                        --k0;
                    k = k0;
                }
                else
                {
                    int j0 = j + 1;
                    while (j0 < k && nums[j0] == nums[j])
                        ++j0;
                    j = j0;
                }
            }
        }
        return ans;
    }
};
// @lc code=end