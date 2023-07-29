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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        stack<ListNode*> st;
        while(head->next != NULL){
            st.push(head);
            head = head->next;
        }
        ListNode* cur = head;
        while(!st.empty()){
            cur->next = st.top();
            cur = st.top();
            cur->next = NULL;
            st.pop();
        }
        return head;
    }
};