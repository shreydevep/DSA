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
   int greaterNodes = 0;
   void recurr(TreeNode* node){
      if(!node) return;
      recurr(node->right);
      greaterNodes += node->val;
      node->val = greaterNodes;
      recurr(node->left);
        
    }
    TreeNode* bstToGst(TreeNode* root) {
         recurr(root);
         return root;
    }
};