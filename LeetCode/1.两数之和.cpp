/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */
#include <bits/stdc++.h>
using namespace std;
// O(n logn), but faster...
// struct Data{
//     int num,index;
//     friend bool operator<(const Data& l,const Data& r){
//         return l.num<r.num;
//     }
// };
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         vector<Data> datas(nums.size());
//         for(int i = 0; i < nums.size(); i++){
//             datas[i]={nums[i],i};
//         }
//         sort(datas.begin(),datas.end());
//         int l = 0;
//         int r = datas.size() - 1;
//         while(datas[l].num + datas[r].num != target){
//             if(datas[l].num + datas[r].num < target){
//                 l++;
//             }
//             else{
//                 r--;
//             }
//         }
//         vector<int> result = {datas[l].index,datas[r].index};
//         return result;
//     }
// };
// @lc code=start
// O(n), but slower...
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        mp.reserve(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            auto it = mp.find(target - nums[i]);
            if (it != mp.end()) {
                return {it->second, i};
            }
            mp[nums[i]] = i;
        }
        return {0, 0};
    }
};
// @lc code=end
