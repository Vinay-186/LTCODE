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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        ListNode* cur = head;
        while(cur){
            n++;
            cur = cur->next;
        }
        if(n == 0) return vector<ListNode*>(k, NULL);
        vector<ListNode*> list;
        int no_parts = k;
        while(head){
            int len = (n % k == 0)? n / k : n/ k + 1;
            n -= len;
            k--;
            list.push_back(head);
            for(int i = 0; i < len - 1; i++) head = head->next;
            ListNode* temp = head->next;
            head->next = NULL;
            head = temp;
        }
        
        while(list.size() != no_parts) list.push_back(NULL);
        return list;
    }
};