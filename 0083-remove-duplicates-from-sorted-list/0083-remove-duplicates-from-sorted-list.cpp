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
    void del(ListNode* prev, ListNode* cur){
        prev->next = cur->next;
        delete cur;
    }
    
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* temp = head;
        while(head){
            if(prev == NULL){
                prev = head;
                head = head->next;
                continue;
            }
            if(prev->val == head->val) {
                ListNode* nodeToBeDel = head;
                head = head->next;
                del(prev, nodeToBeDel);
            }else{
                prev = head;
                head = head->next;
            }
        }
        return temp;
    }
};