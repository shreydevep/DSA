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
    TreeNode* ans;
    void inorder(TreeNode* node,int &k,int &sz){
        if(!node) return;
       
        
        inorder(node->left,k,sz);
        sz++;
         if(sz == k) {
            ans = node;
            return;
        }
        inorder(node->right,k,sz);
        
    }
    int kthSmallest(TreeNode* root, int k) {
        int sz = 0;
        inorder(root,k,sz);
        return ans->val;
    }
};