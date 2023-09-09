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
    ListNode* successor = NULL;
    ListNode* tail = NULL;
    ListNode* reverseN(ListNode* head, int n){
        if(n == 1){
            successor = head->next;
            return head;
        }
        ListNode* last = reverseN(head->next, n-1);
        head->next->next = head;
        head->next = successor;
        tail = head;
        return last;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1) return head;
        int n = 0;
        for(ListNode* i = head; i != NULL; i = i->next) n++;
        ListNode* newHead = NULL, *next_tail;
        while(n >= k){
            if(newHead == NULL) {
                newHead = reverseN(head, k);
                next_tail = tail;
            }else {
                ListNode* temp = reverseN(successor, k);
                next_tail->next = temp;
                next_tail = tail;
            }
            n-= k;
        }
        return newHead;
    }
};