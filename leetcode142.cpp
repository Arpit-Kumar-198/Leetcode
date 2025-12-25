/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) return NULL; 
        // unordered_set<ListNode*> st;
        // ListNode* temp = head;
        // while(temp && st.count(temp) == 0){
        //     st.insert(temp);
        //     temp = temp->next;
        // }
        // return temp;

        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast != NULL && fast->next != NULL){
            if(slow == fast) break;
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast == NULL || fast->next == NULL) return NULL;
        fast = head;
        slow = slow->next;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};