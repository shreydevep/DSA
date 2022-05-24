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
    bool isSameTree(TreeNode* p,TreeNode* q){
        if(p == NULL && q == NULL) return true;
        if(p != NULL && q != NULL){
            if(p->val != q->val){
                return false;
            }
            return (isSameTree(p->left,q->left) && isSameTree(p->right,q->right));
        }
        else{
            return false;
        }
    }
    bool ans = false;
    bool check(TreeNode* root,TreeNode* subRoot){
        if(root == NULL) return false;
        ans |= isSameTree(root,subRoot);
        if(ans){
            return ans;
        }
        return (check(root->left,subRoot) or check(root->right,subRoot));
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
         check(root,subRoot);
         return ans;
    }
};