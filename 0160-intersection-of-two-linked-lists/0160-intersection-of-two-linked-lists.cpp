/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tempHeadA = headA;
        ListNode* tempHeadB = headB;
        while(headA != headB){
            headA = headA ? headA->next : tempHeadA;
            headB = headB ? headB->next : tempHeadB;
        }
        return headA;
    }
};