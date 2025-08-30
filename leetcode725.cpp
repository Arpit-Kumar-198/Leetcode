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
        vector<ListNode*> splitListToParts(ListNode* head, int k) {
            vector<ListNode*> ans;
            if(k==1) {
                ans.push_back(head);
                return ans;
            }
            
            int size = 0;
            ListNode* temp = head;
            while(temp!=NULL){
                temp = temp->next;
                size++;
            }
            int len = size/k;
            int rm = size%k;
    
            if(k >= size){
                ListNode* temp = head;
               
                while(temp!=NULL){
                     ListNode* t = new ListNode(temp->val);
                     t->next = NULL;
                    ans.push_back(t);
                    temp = temp->next;
                    k--;
                }
                while(k>0){
                    ans.push_back(NULL);
                    k--;
                }
                return ans;
            }
    
            temp = head;
            // ListNode* first = new ListNode(-1);
            // ListNode* f = first;
           
            while(temp!=NULL){
                int x = len;
                ListNode* remain = new ListNode(-1);
                ListNode* r = remain;
                while(x>0){
                    r->next = temp;
                    temp = temp->next;
                    r = r->next;
                    x--;
                }
                if(rm>0){
                    r->next = temp;
                    temp = temp->next;
                    r = r->next;
                    rm--;
                }
                r->next = NULL;
                ans.push_back(remain->next);
            }
            
            return ans;
    
        }
    };