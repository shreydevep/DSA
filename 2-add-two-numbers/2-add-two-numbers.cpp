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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* pseudoHead = new ListNode(-1);
        ListNode* node = pseudoHead;
        
        while(l1 != NULL && l2 != NULL){
            int sum = l1->val + l2->val + carry;
            l1->val = (sum % 10);
            carry = sum / 10;
            node->next = l1;
            node = node->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1 != NULL){
            int sum = l1->val + carry;
            l1->val = (sum % 10);
            carry = sum / 10;
            node->next = l1;
            node = node->next;
            l1 = l1->next;
       }
       while(l2 != NULL){
            int sum = l2->val + carry;
            l2->val = (sum % 10);
            carry = sum / 10;
            node->next = l2;
            node = node->next;
            l2 = l2->next;
       }
       if(carry != 0){
           ListNode* temp = new ListNode(carry);
           node->next = temp;
       }
       return pseudoHead->next;
    }
};