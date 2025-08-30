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
        ListNode* middleNode(ListNode* head) {
            
            // int size = 0;
            // ListNode* midNode = NULL;
            // ListNode* temp = head;
            // while(temp != NULL){
            //     size++;
            //     temp = temp->next;
            // }
            // delete temp;
            // int p = size/2 + 1;
            // int p2 = 1;
            //     ListNode* t = head;
            //     while(p2 != p){
            //         t = t->next;
            //         p2++;
            //     }
            //     if(size == 1) return head;
                
            //   return  midNode = t;





            //Slow and fast pointer technique       interviewer ko yhi chahiye
            ListNode* slow = head;
            ListNode* fast = head;
    
            while(fast != NULL && fast->next != NULL){
                slow = slow->next;
                fast = fast->next->next;
            }
            return slow;  
        }
    };