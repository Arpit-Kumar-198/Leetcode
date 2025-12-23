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
        // int len = 0;
        // ListNode* temp = head;
        // while(temp) {
        //     len++;
        //     temp = temp->next;
        // }
        // if(len == 0 || len == 1) return head;
        // if(len == 2) return head->next;
        // temp = head;
        // int idx = 1;
        // while(temp && idx < len/2) {
        //     temp = temp->next;
        //     idx++;
        // }
        // return temp->next;

        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};