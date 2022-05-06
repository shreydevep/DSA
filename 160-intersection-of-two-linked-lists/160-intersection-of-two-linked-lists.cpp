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
        set<ListNode*> ptrA;
        while(headA != NULL){
            ptrA.insert(headA);
            headA = headA->next;
        }
        while(headB != NULL){
            if(ptrA.find(headB) != ptrA.end()) return headB;
            headB = headB->next;
        }
        
        return NULL;
    }
};