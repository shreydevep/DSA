/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<TreeNode*>> ancestors;
    void dfs(TreeNode* root,TreeNode* p,vector<TreeNode*> &ancestor){
        if(!root) return;
        
        if(root == p){
            ancestor.push_back(p);
            ancestors.push_back(ancestor);
            ancestor.pop_back();
            return;
        }
        ancestor.push_back(root);
        dfs(root->left,p,ancestor);
        dfs(root->right,p,ancestor);
        ancestor.pop_back();
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
       
        vector<TreeNode*> temp;
        dfs(root,p,temp);
        temp.clear();
        dfs(root,q,temp);
        temp.clear();
        auto ancestor1 = ancestors[0];
        auto ancestor2 = ancestors[1];
        int ptr = 0;
        while(ptr < min(ancestor1.size(),ancestor2.size()) && ancestor1[ptr] == ancestor2[ptr]){
            ptr++;
        }
        return ancestor1[ptr-1];
        
    }
};