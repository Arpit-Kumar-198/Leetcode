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
 int length(ListNode* head){
    ListNode* t = head;
    int l = 0;
    while(t) {
        l++;
        t = t->next;
    }
    return l;
 }

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL) return head;
        int n = length(head);
        k = k%n;
        if(k == 0) return head;
        k = n-k;
        int i = 0;
        ListNode* temp = head;
        ListNode* track = NULL;
        while(temp && i < k-1){
            i++;
            temp = temp->next;
        }
        track = temp->next;
        temp->next = NULL;

        temp = track;
        while(temp->next) temp = temp->next;

        temp->next = head;
        head = track;

        return head;
    }
};