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
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* i = head;
        ListNode* res = new ListNode(-1);
        ListNode* p = res;
        ListNode* large = new ListNode(-1);
        ListNode* temp = large;
        while(i){
            ListNode* t = i->next;
            if(i->val < x){
                p->next = i;
                p = p->next;
                if(p->next) p->next = NULL;
            }
            else{
                temp->next = i;
                temp = temp->next;
                if(temp->next) temp->next = NULL;
            }
            i = t;
        }
        p->next = large->next;
        return res->next;
    }
};