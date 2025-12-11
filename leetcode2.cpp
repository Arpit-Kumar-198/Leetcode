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
 ListNode* helper(ListNode* n1, ListNode* n2, ListNode* carry){
    if(n2 == NULL){
        ListNode* f = new ListNode(-1);
        ListNode* t = f;
        while(n1){
            int x = n1->val + carry->val;
            t->next = new ListNode(x%10);
            carry->val = x/10;
            t = t->next;
            n1 = n1->next;
        }
        if(carry->val != 0) t->next = carry;
        return f->next;
    }
    if(n1->val + n2->val + carry->val <= 9) {
        int x = n1->val + n2->val + carry->val;
        carry->val = 0;
        return new ListNode(x);
    }
    int x = n1->val + n2->val + carry->val;
    carry->val = x/10;
    return new ListNode(x%10);
 }
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* ans = new ListNode(-1);
        ListNode* res = ans;
        ListNode* carry = new ListNode(0);

        ListNode* temp1 = l1;
        ListNode* temp2 = l2;

        while(temp1 && temp2){
            res->next = helper(temp1,temp2,carry);
            res = res->next;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        if(!temp1 && !temp2 && carry->val != 0) res->next = carry;
        else if(temp1) res->next = helper(temp1, NULL, carry);
        else if(temp2) res->next = helper(temp2, NULL, carry);
        
        return ans->next;

    }
};