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
    ListNode* reverse(ListNode* head){
        ListNode* ptr = head;
        ListNode* newHead = NULL;
        while(ptr != NULL){
            ListNode* next = ptr->next;
            ptr->next = newHead;
            newHead = ptr;
            ptr = next;
        }
        return newHead;
    }
    bool isPalindrome(ListNode* head) {
        if(head->next == NULL) return true;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        slow = (fast)? reverse(slow->next) : reverse(slow);
        fast = head;
        while(slow != NULL){
            if(slow->val != fast->val) return false;
            slow = slow->next;
            fast = fast->next;
        }
        return true;
    }
};