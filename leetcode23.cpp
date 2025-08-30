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
   ListNode* mergeKLists(vector<ListNode*>& lists) {
       if(lists.empty()) return NULL;
       int n = lists.size();
       int idx = n-1;
      while(lists.size()!=1){
       ListNode* l1 = lists[idx];
       lists.pop_back();
       ListNode* l2 = lists[idx-1];
       lists.pop_back();
       ListNode* t = mergeTwoLists(l1,l2);
       lists.push_back(t);
       idx--;
      }

       return lists[0];



      // better approach
       if(lists.empty()) return NULL;
       while(lists.size()!=1){
        ListNode* l1 = lists[0];
        lists.erase(lists.begin());
        ListNode* l2 = lists[0];
        lists.erase(lists.begin());
        ListNode* t = mergeTwoLists(l1,l2);
        lists.push_back(t);
       
       }

        return lists[0];

        // T.C. = n*log(k)
       
   }
};