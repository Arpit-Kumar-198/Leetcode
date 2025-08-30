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
            if(head==NULL || head->next==NULL) return head;
            ListNode* left = new ListNode(-101);
             ListNode* l = left;
              ListNode* c = left;
            ListNode* right = new ListNode(-101);
             ListNode* r = right;
             ListNode* temp = head;
            while(temp!=NULL){
                if(temp->val < x){
                    left->next = temp;
                    left = left->next;
                    temp = temp->next;
                }
                else {
                    right->next = temp;
                    right = right->next;
                    temp = temp->next;
                }
            }
            left->next = NULL;
            right->next = NULL;
            while(l->next!=NULL){
                l = l->next;
            }
            l->next = r->next;
    
    
            return c->next;
    
        }
    };