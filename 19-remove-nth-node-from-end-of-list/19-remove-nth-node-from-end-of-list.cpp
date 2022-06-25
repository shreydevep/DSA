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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* node = head;
        int len = 0;
        while(node != NULL){
            len++;
            node = node->next;
        }
        n = len - n;
        if(n == 0){
            return head->next;
        }
        node = head;
        ListNode* prev = head;
        while(n--){
            prev = node;
            node = node->next;
        }
        
        prev->next = node->next;
        delete node;
        return head;
        
    }
};