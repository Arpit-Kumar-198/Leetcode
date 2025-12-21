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

    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* temp = head;
        ListNode* store1 = head->next;
        ListNode* store2 = NULL;
        temp->next = NULL;

        while(store1){
            store2 = store1->next;
            store1->next = temp;
            temp = store1;
            store1 = store2;
        }
        head = temp;
        while(temp->next != NULL) temp = temp->next;
        temp->next = NULL;
        return head;

    }
};