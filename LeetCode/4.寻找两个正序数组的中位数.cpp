/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        double ans = findKth(nums1,nums2,((m + n + 1) >> 1));
        if(!((m+n)&1)){
            ans += findKth(nums1,nums2,((m + n + 1) >> 1) + 1);
            ans /= 2;
        }
        return ans;
    }
    int findKth(vector<int>& nums1, vector<int>& nums2,int k){
        if(nums1.size() > nums2.size()) return findKth(nums2,nums1,k);
        int l = 0, r = min(k - 1,(int)nums1.size() - 1);
        while(l <= r){
            int i = (l + r) >> 1;
            int j = k - 1 - i;
            if((j <= 0 || nums2[j - 1]<=nums1[i])&&( j >= nums2.size() || nums1[i]<=nums2[j])){
                return nums1[i];
            }
            if(j < nums2.size() && nums1[i] > nums2[j]){
                if(i <= 0 || nums2[j] >= nums1[i - 1])
                    return nums2[j];
                r = i - 1;
            }
            else{
                l = i + 1;
            }
        }
        return nums2[k - nums1.size() - 1];
    }
};
// @lc code=end