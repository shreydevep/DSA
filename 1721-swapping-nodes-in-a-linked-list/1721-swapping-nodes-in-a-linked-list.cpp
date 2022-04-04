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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* start = head;
        ListNode* end = head;
        ListNode* curr = head;
        k--;
        while(curr->next){
            if(k > 0){
                start = start ->next;
                curr= curr->next;
            }
            else{
                end = end->next;
                curr = curr->next;
            }
            k--;
        }
       
        swap(start->val,end->val);
        return head;
    }
};