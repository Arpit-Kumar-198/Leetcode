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
        ListNode* removeNthFromEnd(ListNode* head, int n) {
            if(head->next==NULL){
                head = NULL;
                return head;
            }
            ListNode* slow;
            ListNode* fast;
            slow = head;
            fast = head;
            if(n==1){
                
            while(fast->next->next!=NULL){
                fast=fast->next;
            }
            fast->next = NULL;
            return head;
        }
    
            for(int i = 0; i < n; i++) fast = fast->next;
            while(fast!=NULL){
                slow = slow->next;
                fast = fast->next;
            }
    
            slow->val = slow->next->val;
            slow->next = slow->next->next;
            
    
            return head;
        }
    };