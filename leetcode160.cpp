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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* p1 = headA;
        ListNode* p2 = headB;
        int n1 = 0, n2 = 0;
        while(p1){
            n1++;
            p1 = p1->next;
        }
        while(p2){
            n2++;
            p2 = p2->next;
        }
        p1 = headA, p2 = headB;
        ListNode* res = NULL;
        while(p1 && p2){
            if(p1 == p2) {
                res = p1;
                break;
            }
            else if(n1 >= n2) {
                p1 = p1->next;
                n1--;
            }
            else {
                p2 = p2->next;
                n2--;
            }
        }
        return res;
    }
};