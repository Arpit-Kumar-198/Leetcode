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
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
         ListNode* tA = list1;
         ListNode* tB = list2;
         ListNode* c = new ListNode(-1);
         ListNode* tC = c;
         while(tA!=NULL && tB!=NULL){
            if(tA->val < tB->val){
                ListNode* temp = new ListNode(tA->val);
                tC->next = temp;
                tC = temp;
                tA = tA->next;
            }
            else{
                ListNode* temp = new ListNode(tB->val);
                tC->next = temp;
                tC = temp;
                tB = tB->next;
            }
         }
         if(tA==NULL){
          while(tB!=NULL){
              ListNode* temp = new ListNode(tB->val);
                tC->next = temp;
                tC = temp;
                tB = tB->next;
          }
         }
         if(tB==NULL){
                while(tA!=NULL){
                    ListNode* temp = new ListNode(tA->val);
                tC->next = temp;
                tC = temp;
                tA = tA->next;
                }
         }
        
         return c->next;
        }

    };



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
    };