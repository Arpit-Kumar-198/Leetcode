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
    ListNode* reverseList(ListNode* head) {
       if(head == NULL) return NULL;
       ListNode* temp = head;
       head = head->next;
       temp->next = NULL;
       while(head!=NULL){
           ListNode* t = head;
           head = head->next;
           t->next = temp;
           temp = t;
           
       }
       return temp;

   }
public:
   void reorderList(ListNode* head) {
       ListNode* slow = head;
       ListNode* fast = head;
       while(fast->next!=NULL && fast->next->next!=NULL){
           slow = slow->next;
           fast = fast->next->next;
       }
       ListNode* c = slow->next;
       slow->next = NULL;
       ListNode* rev = reverseList(c);
       ListNode* temp = head;
       while(rev!=NULL && temp!=NULL){
           ListNode* t = temp->next;
           temp->next = rev;
           ListNode* t2 = rev->next;
           rev->next = t;
           temp = t;
           rev = t2;
       }
       
   }
};