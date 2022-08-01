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
    class ComparisonClass {
    public:
        bool operator() (const ListNode* A, const ListNode* B) {
            return (A->val > B->val);
        }
    };
    ListNode* mergeList(vector<ListNode*> &lists){
        ListNode* phead = new ListNode(0);
        ListNode* p = phead;
        priority_queue<ListNode*,vector<ListNode*>,ComparisonClass> pq;
        for(auto &ptr : lists){
            if(ptr)
                pq.push(ptr);
        }
        while(!pq.empty()){
            auto node = pq.top();
            pq.pop();
            p->next = node;
            if(node->next)
                pq.push(node->next);
            node->next = NULL;
            p = node;
        }
        return phead->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return mergeList(lists);
    }
};