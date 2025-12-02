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
        if(head == NULL || head->next == NULL) return head;
        ListNode* res = new ListNode(-1);
        ListNode* t = res;
        ListNode* temp = head;
        while(temp){
            if(temp->next == NULL) {
                t->next = temp;
                t = t->next;
                temp = temp->next;
            }
            else if(temp->val != temp->next->val){
                t->next = temp;
                t = t->next;
                temp = temp->next;
            }
            else{
                while(temp && temp->next && temp->val == temp->next->val) temp = temp->next;
                if(temp->next == NULL){
                    t->next = NULL;
                    break;
                }
                else temp = temp->next;
            }
        }
        return res->next;
    }
};