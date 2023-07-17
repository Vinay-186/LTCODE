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
    ListNode* newH(ListNode* curHead, int val){
        ListNode* newHead = new ListNode(val);
        newHead->next = curHead;
        return newHead;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        while(l1 != NULL){
            s1.push(l1->val);
            l1=l1->next;
        }
        while(l2 != NULL){
            s2.push(l2->val);
            l2 = l2->next;
        }
        ListNode* newHead = NULL;
        int carry = -1;
        while(!s1.empty() && !s2.empty()){
            int val = s1.top() + s2.top();
            if(carry != -1) {
                val += carry;
                carry = -1;
            }
            s1.pop(), s2.pop();
            if(val > 9){
               int temp = val;
               temp/=10;
               carry = temp % 10;
               val = val % 10;
            }
            newHead = newH(newHead, val); 
        }
        if(s1.empty()) s1 = s2;
        while(!s1.empty()){
            int val = s1.top();
            if(carry != -1){
                val += carry;
                carry = -1;
            }
            s1.pop();
            if(val > 9){
               int temp = val;
               temp/=10;
               carry = temp % 10;
               val = val % 10;
            }
            newHead = newH(newHead, val);  
        }
        if(carry != -1) newHead = newH(newHead, carry);
        return newHead;
    }
};