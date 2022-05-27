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
    int rt = 0;
    TreeNode* build(int lr,int rr,vector<int> &preorder){
        if(rt >= preorder.size()) return NULL;
        if(preorder[rt] < lr || preorder[rt] > rr){
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[rt]);
        rt++;
        
        root->left = build(lr,root->val,preorder);
        root->right = build(root->val,rr,preorder);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return build(-1e8,1e8,preorder);
    }
};