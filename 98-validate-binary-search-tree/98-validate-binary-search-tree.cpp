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
    bool check(TreeNode* root){
        if(!root) return true;
        
        if(!check(root->left)) return false;
        
        if(prev != NULL && prev->val >= root->val) return false;
        prev = root;
        if(!check(root->right)) return false;
        
        return true;
    }
    
    bool isValidBST(TreeNode* root) {
        
        return check(root);    
    }
};