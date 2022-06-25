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
    ListNode* detectCycle(ListNode* head) {
    if (head == NULL || head->next == NULL) return NULL;
    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* start = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            while (slow != start) {
                slow = slow->next;
                start = start->next;
            }
            return start;
        }
    }
    return NULL;
}
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* A = headB;
        while(A->next !=NULL){
            A = A->next;
        }
        A->next = headB; //Temp Link
        
        auto intersection = detectCycle(headA);
        
        A->next = NULL;
        return intersection;
    }
    
};