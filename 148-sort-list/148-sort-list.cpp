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
    ListNode* sortList(ListNode* head) {
        vector<int> res;
        ListNode* node = head;
        while(node){
            res.push_back(node->val);
            node = node->next;
        }
        sort(res.begin(),res.end());
        node = head;
        int i = 0;
        while(node){
            node->val = res[i];
            i++;
            node = node->next;
        }
        return head;
    }
};