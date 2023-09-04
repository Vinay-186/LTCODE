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
    ListNode* merge(ListNode* head1, ListNode* head2) {
        ListNode* temp = new ListNode(-1);
        ListNode* cur = temp;
        
        while (head1 && head2) {
            if (head1->val <= head2->val) {
                cur->next = head1;
                head1 = head1->next;
            } else {
                cur->next = head2;
                head2 = head2->next;
            }
            cur = cur->next;
        }
        
        if (head1) cur->next = head1;
        else cur->next = head2;
    
        return temp->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n == 0) return NULL;
        if(n == 1) return lists[0];
        ListNode* last = merge(lists[n-2], lists[n-1]);
        n -= 2;
        while(n >= 0){
            n--;
            if(n < 0) break;
            last = merge(lists[n], last);
        }
        return last;
    }
};