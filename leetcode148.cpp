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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* tA = list1;
        ListNode* tB = list2;
        ListNode* c = new ListNode(-1);
        ListNode* tC = c;
        while(tA!=NULL && tB!=NULL){
           if(tA->val < tB->val){
               tC->next = tA;
               tC = tC->next;
               tA = tA->next;
           }
           else{
               tC->next = tB;
               tC = tC->next;
               tB = tB->next;
           }
        }
        if(tA==NULL){
         while(tB!=NULL){
               tC->next = tB;
               tC = tC->next;
               tB = tB->next;
         }
        }
        if(tB==NULL){
               while(tA!=NULL){
                
               tC->next = tA;
               tC = tC->next;
               tA = tA->next;
               }
        }
       
        return c->next;
       }
  
public:
   ListNode* sortList(ListNode* head) {
       if(head==NULL) return NULL;
       if(head->next==NULL) return head;
     ListNode* slow = head;
     ListNode* fast = head;
     while(fast->next!=NULL && fast->next->next!=NULL){
       slow = slow->next;
       fast = fast->next->next;
     }

   ListNode* left = head;
   ListNode* right = slow->next;
   slow->next=NULL;
     

     left = sortList(left);
     right = sortList(right);
    return mergeTwoLists(left,right);

     
   }
};