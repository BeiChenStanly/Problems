/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 */
#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
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
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == nullptr)
            return list2;
        else if (list2 == nullptr)
            return list1;
        else if (list1->val < list2->val)
        {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        else
        {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
    // ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    // {
    //     ListNode *result = new ListNode();
    //     ListNode *now = result;
    //     while (list1 != nullptr && list2 != nullptr)
    //     {
    //         now->next = new ListNode();
    //         now = now->next;
    //         if (list1->val < list2->val)
    //         {
    //             now->val = list1->val;
    //             list1 = list1->next;
    //         }
    //         else
    //         {
    //             now->val = list2->val;
    //             list2 = list2->next;
    //         }
    //     }
    //     now->next = list1 == nullptr?list2:list1;
    //     return result->next;
    // }
};
// @lc code=end
