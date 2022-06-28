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
    int countSetBits(int n)
    {
    // base case
        if (n == 0)
            return 0;
        else
            return 1 + countSetBits(n & (n - 1));
    }
    bool check(int mask){
        if(countSetBits(mask) == 0 or countSetBits(mask) == 1) return true;
        return false;
    }
    void recurr(TreeNode* root,int mask){
        
        if(root == NULL) return;
        mask ^= (1 << (root->val-1));
        if(root->left == NULL && root->right == NULL){
            ans += check(mask);
            return;
        }
        recurr(root->left,mask);
        recurr(root->right,mask);
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        int mask = 0;
        recurr(root,mask);
        return ans;
    }
};