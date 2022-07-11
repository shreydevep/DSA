/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* node = root;
        if(p->val > q->val){
            swap(p,q);
        }
        while(node != NULL){
            if(p->val <= node->val && q->val >= node->val) return node;
            else{
                if(p->val <= node->val && q->val <= node->val){
                    node = node->left;
                }
                else{
                    node = node->right;
                }
            }
        }
        return node;
    }
};