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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* prev = NULL;
        ListNode* start = head;
        ListNode* nthNode = head;
        while(n > 0){
            nthNode = nthNode->next;
            n--;
        }
        while(nthNode != NULL){
            prev = start;
            start= start->next;
            nthNode = nthNode->next;
        }
        if(prev == NULL) return head->next;
        prev->next = start->next;
        start = NULL;
        return head;
    }
};