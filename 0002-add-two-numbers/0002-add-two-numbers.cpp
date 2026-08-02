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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* d = new ListNode(0);
        ListNode* p = l1;
        ListNode* q = l2; 
        ListNode* curr = d;
        int carry = 0 , sum = 0;
        while(p!=NULL || q!=NULL){
            int x = ((p == NULL) ? 0 : p->val);
            int y = ((q == NULL )? 0 : q->val);
            int sum = x + y + carry;
            carry = sum/10;
            curr->next = new ListNode(sum%10);
            curr = curr->next;
            if(p!=NULL) p = p->next;
            if(q!=NULL) q = q->next;
        }
        if(carry > 0){
            curr->next = new ListNode(carry);
        }
        return d->next;
    }
};