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
    int ans;
    bool check(bitset<9> &mask){
        if(mask.count() == 0 or mask.count() == 1) return true;
        return false;
    }
    void recurr(TreeNode* root,bitset<9> &mask){
        
        if(root == NULL) return;
        mask.set(root->val-1,mask[root->val-1]^(1));
        if(root->left == NULL && root->right == NULL){
            ans += check(mask);
            mask.set(root->val-1,mask[root->val-1]^(1));
            return;
        }
        
        recurr(root->left,mask);
        recurr(root->right,mask);
        mask.set(root->val-1,mask[root->val-1]^(1));
        
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        bitset<9> mask(0);
        recurr(root,mask);
        return ans;
    }
};