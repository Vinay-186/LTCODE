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
    ListNode* insert(ListNode* node1, ListNode* list){
        ListNode* prev = NULL;
        ListNode* temp = list;
        while(list && node1->val > list->val ){
            prev = list;
            list = list->next;
        }
        if(prev == NULL){
            node1->next = list;
            return node1;
        }
        prev->next = node1;
        node1->next = list;
        return temp;
    }
    ListNode* sortL(ListNode* prev, ListNode* head) {
        if(!head->next) return head;
        sortL(head, head->next);
        ListNode* list = head->next;
        head->next = NULL;
        head = insert(head, list);
        if(prev) prev->next = head;
        return head;
    }
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        return sortL(NULL, head);
    }
};