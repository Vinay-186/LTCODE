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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL) return head;
        int len = 1;
        ListNode* ptr = head;
        while(ptr->next != NULL){
            ptr = ptr->next;
            len++;
        }
        k %= len;
        if(k == 0) return head;
        ListNode *newTail = NULL, *cur = head;
        ptr = head;
        while(k--) ptr = ptr->next;
        
        while(ptr->next != NULL){
            newTail = cur;
            cur = cur->next;
            ptr = ptr->next;
        }
        ListNode *newHead = cur->next;
        newTail = cur;
        newTail->next = NULL;
        ptr->next = head;
        return newHead;
    }
};