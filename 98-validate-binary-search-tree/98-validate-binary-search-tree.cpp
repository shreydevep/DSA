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
    TreeNode* prev = NULL;
    bool recurr(TreeNode* node){
        if(!node) return true;
        
        if(!recurr(node->left)) return false;
        
        if(prev != NULL && prev->val >= node->val) return false;
        prev = node;
        
        if(!recurr(node->right)) return false;
        
        return true;
        
    }
    bool isValidBST(TreeNode* root) {
        return recurr(root);
    }
};