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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* prev = NULL;
        ListNode* cur = head;
        while(cur && cur->next){
            if(cur->next->val == cur->val){
                int val = cur->val;
                while(cur && cur->val == val)  cur = cur->next;
                if(prev) prev->next = cur;
                else head = cur;
            }else{
                prev = cur;
                cur = cur->next;
            }
        }
        return head;
    }
};