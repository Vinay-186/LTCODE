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
        ListNode* sentinel = new ListNode(-1);
        ListNode* head = sentinel;
        int carry = 0;
        while(l1 != NULL && l2 != NULL){
            int val = l1->val + l2->val + carry;
            carry = 0;
            int node_val = val % 10;
            carry = val / 10;
            sentinel->next = new ListNode(node_val);
            sentinel = sentinel->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1 != NULL){
            int val = l1->val + carry;
            carry = 0;
            int node_val = val % 10;
            carry = val / 10;
            sentinel->next = new ListNode(node_val);
            sentinel = sentinel->next;
            l1 = l1->next;
        }
        
        while(l2 != NULL){
            int val = l2->val + carry;
            carry = 0;
            int node_val = val % 10;
            carry = val / 10;
            sentinel->next = new ListNode(node_val);
            sentinel = sentinel->next;
            l2 = l2->next; 
        }
        
        sentinel->next = carry > 0 ? new ListNode(carry) : NULL;
        
        return head->next;
    }
};