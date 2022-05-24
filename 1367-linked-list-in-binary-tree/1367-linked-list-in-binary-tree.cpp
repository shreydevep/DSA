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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = false;
    bool isListPath(TreeNode* root,ListNode* head){
        if(root != NULL && root->val == head->val && head->next == NULL) return true;
        if(root == NULL) return false;
        
        if(root->val == head->val){
            return (isListPath(root->left,head->next) or isListPath(root->right,head->next));
        }
            else {
                return false;
            }
        }
    bool posPath(TreeNode* root,ListNode* head){
        if(root == NULL) return false;
        
        ans |= isListPath(root,head);
        if(ans) return true;
        return (posPath(root->left,head) or posPath(root->right,head));
        
    }
    
    bool isSubPath(ListNode* head, TreeNode* root) {
        return posPath(root,head);
    }
};