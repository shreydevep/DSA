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
    ListNode* recursiveReverse(ListNode* node,ListNode* prev){
        if(node == NULL) return prev;
         auto head = recursiveReverse(node->next,node);
         node->next = prev;
         return head;
    }
    ListNode* reverseList(ListNode* head) {
        return recursiveReverse(head,NULL);
    }
};