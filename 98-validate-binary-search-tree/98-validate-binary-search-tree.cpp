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
   vector<int> inorderEle;
    void inorder(TreeNode* root){
        if(!root) return ;
        
        inorder(root->left);
        inorderEle.push_back(root->val);
        inorder(root->right);
    }
    
    bool isValidBST(TreeNode* root) {
        inorder(root);
        int mn = inorderEle[0];
        for(int i=1;i<inorderEle.size();++i){
           if(mn >= inorderEle[i] || inorderEle[i-1] >= inorderEle[i]){
               return 0;
           }
            mn = min(inorderEle[i],mn);
        }
        return 1;
        
        
    }
};