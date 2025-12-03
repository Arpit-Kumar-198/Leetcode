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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* res = new ListNode(-1);
        ListNode* t = res;
        ListNode* i = head;
        ListNode* j = head->next;
  
        ListNode* restore = NULL;
        while(i && j){
            t->next = j;
            restore = j->next;
            t = t->next;
            t->next = i;
            t = t->next;
            t->next = restore;
            i = i->next;
            if(i) j = i->next;
        }
        return res->next;
    }
};