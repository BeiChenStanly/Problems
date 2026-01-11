/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */
#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return addTwoNumbersWithAddition(l1,l2,0);
    }
    ListNode* addTwoNumbersWithAddition(ListNode* l1, ListNode* l2,int addition){
        if(l1 == nullptr && l2 == nullptr){
            if(addition!=0) return new ListNode(addition);
            else return nullptr;
        }
        if(l1 != nullptr && l2 != nullptr) return new ListNode((l1->val+l2->val+addition)%10,addTwoNumbersWithAddition(l1->next,l2->next,(l1->val+l2->val+addition)/10));
        if(l1 == nullptr) return addNumberAndAddition(l2,addition);
        return addNumberAndAddition(l1,addition);
    }
    ListNode* addNumberAndAddition(ListNode* l,int addition){
        if(l==nullptr){
            if(addition) return new ListNode(addition);
            return nullptr;
        }
        l->val += addition;
        if(l->val < 10){
            return l;
        }
        return new ListNode((l->val)%10,addNumberAndAddition(l->next,(l->val)/10));
    }
};
// @lc code=end
