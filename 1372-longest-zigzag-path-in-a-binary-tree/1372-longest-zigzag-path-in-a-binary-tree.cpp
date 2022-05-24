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
    class Mypair{
        public:
        int forwardSlope = -1;
        int backwardSlope = -1;
        int maxLen = 0;
        ~Mypair();
    };
    int ans = 0;
    Mypair* dfs(TreeNode* root){
        if(!root) return new Mypair();
        
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        
        Mypair *ansCurr = new Mypair();
           ansCurr->maxLen = max(max(left->maxLen,right->maxLen),max(left->backwardSlope,right->forwardSlope) + 1); 
        
            ansCurr->backwardSlope = right->forwardSlope + 1;
            ansCurr->forwardSlope = left->backwardSlope + 1;
        return ansCurr;
       
        
        
        
    }
    int longestZigZag(TreeNode* root) {
       return dfs(root)->maxLen;
    }
};