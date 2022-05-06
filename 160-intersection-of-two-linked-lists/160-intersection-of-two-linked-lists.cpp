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
        int lenA = 0;
        int lenB = 0;
        ListNode* f = headA;
        ListNode* s = headB;
        while(f != NULL){
            lenA++;
            f = f->next;
        }
        while(s != NULL){
            lenB++;
            s = s->next;
        }
        f = headA;
        s = headB;
        if(lenA < lenB){
            swap(f,s);
        }
        int diff = abs(lenA- lenB);
        while(diff--){
            f = f->next;
        }
        
        while(f != NULL && s != NULL){
            if(f == s) return f;
            f = f->next;
            s = s->next;
        }
        return NULL;
    }
};