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
    int minPath(TreeNode* root){
        if(root == NULL) return INT_MAX;
        
        if(root->left == NULL && root->right == NULL) return 1;
        
        return 1 + min(minPath(root->left),minPath(root->right));
        
        
    }
    int minDepth(TreeNode* root) {
        int ans = minPath(root);
        return (ans == INT_MAX) ? 0 : ans;
    }
};