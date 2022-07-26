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
    TreeNode* bs(TreeNode* node,int val){
        if(!node) return NULL;
        
        if(node->val == val){
            return node;
        }
        else if(node->val < val){
            return bs(node->right,val);
        }
        else{
            return bs(node->left,val);
        }
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        return bs(root,val);
    }
};