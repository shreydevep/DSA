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
    bool recurr(TreeNode* root,int sum,int &targetSum){
        if(!root) return false;
        if(!root->left && !root->right){
           
            if(sum + root->val == targetSum) return 1;
            return 0;
        };
        bool leftAns = false;
        
            leftAns = recurr(root->left,sum + root->val,targetSum);
        
        bool rightAns = false;
        
            rightAns = recurr(root->right,sum + root->val,targetSum);
        
        
        return (leftAns or rightAns);
        
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return recurr(root,0,targetSum);
    }
};