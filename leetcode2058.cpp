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
        vector<int> nodesBetweenCriticalPoints(ListNode* head) {
            vector<int> ans(2,-1);
            if(head==NULL ||  head->next==NULL || head->next->next==NULL){
                return ans;
            }
    
            int maxlen = -1;
            int minlen = -1;
            int len = 0;
            ListNode* temp1 = head;
            ListNode* temp2 = head->next;
            ListNode* temp3 = head->next->next;
    
            int p = 2;
            int pos = 2;
            while(temp1 && temp2 && temp3){
                if((temp2->val < temp1->val && temp2->val < temp3->val) || (temp2->val > temp1->val && temp2->val > temp3->val)){
                    pos = p;
                    temp1 = temp1->next;
                    temp2 = temp2->next;
                    temp3 = temp3->next;
                    break;
                }
                else {
                    p++;
                    temp1 = temp1->next;
                    temp2 = temp2->next;
                    temp3 = temp3->next;
                }
            }
           
            while(temp1 && temp2 && temp3){
                if((temp2->val < temp1->val && temp2->val < temp3->val) || (temp2->val > temp1->val && temp2->val > temp3->val)){
                    len++;
                    maxlen = max(maxlen,len);
                    temp1 = temp1->next;
                    temp2 = temp2->next;
                    temp3 = temp3->next;
                }
                else {
                    len++;
                    temp1 = temp1->next;
                    temp2 = temp2->next;
                    temp3 = temp3->next;
                }
            }
    
            ListNode* temp = head;
            int t = 1;
            while(t!=pos){
                t++;
                temp = temp->next;
            }
            temp1 = temp;
            temp2 = temp->next;
            temp3 = temp->next->next;
             while(temp1 && temp2 && temp3){
                if((temp2->val < temp1->val && temp2->val < temp3->val) || (temp2->val > temp1->val && temp2->val > temp3->val)){
                    t++;
                    minlen = t-pos;
                    pos=t;
                    temp1 = temp1->next;
                    temp2 = temp2->next;
                    temp3 = temp3->next;
                    break;
                }
                else {
                    t++;
                    temp1 = temp1->next;
                    temp2 = temp2->next;
                    temp3 = temp3->next;
                }
            }
             
            while(temp1 && temp2 && temp3){
                if((temp2->val < temp1->val && temp2->val < temp3->val) || (temp2->val > temp1->val && temp2->val > temp3->val)){
                    t++;
                    minlen = min(minlen,t-pos);
                    temp1 = temp1->next;
                    temp2 = temp2->next;
                    temp3 = temp3->next;
                    pos=t;
                }
                else {
                    t++;
                    temp1 = temp1->next;
                    temp2 = temp2->next;
                    temp3 = temp3->next;
                }
            }
            ans[0]= minlen;
            ans[1]=maxlen;
            return ans;
           
        }
    };