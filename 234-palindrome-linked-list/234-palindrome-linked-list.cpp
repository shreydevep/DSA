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
    ListNode* iterativeReverse(ListNode* head){
        if(head == NULL) return head;
        
        ListNode* headNext = head->next;
        ListNode* prev = head;
        prev->next = NULL;
        
        while(headNext != NULL){
            auto temp = headNext->next;
            headNext->next = prev;
            prev = headNext;
            headNext = temp;
        }
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        
        if(fast != NULL){
            slow = slow->next;
        }
        
        
        auto rev = iterativeReverse(slow);
        ListNode* start = head;
        while(rev != NULL){
            if(start->val != rev->val) return false;
            start = start->next;
            rev = rev->next;
        }
        return true;
        
            
    }
};