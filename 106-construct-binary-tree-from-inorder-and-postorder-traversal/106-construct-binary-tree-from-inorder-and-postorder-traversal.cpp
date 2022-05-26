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
    int rt;
    unordered_map<int,int> mp;
    TreeNode* buildTreeFromPostorder(int i,int j,vector<int> &postorder){
        if(i > j) return NULL;
        TreeNode* root = new TreeNode();
        int k = mp[postorder[rt]];
        root->val = postorder[rt];
        rt--;
        root->right = buildTreeFromPostorder(k+1,j,postorder);
        root->left = buildTreeFromPostorder(i,k-1,postorder);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        rt = postorder.size()-1;
        for(int i=0;i<inorder.size();++i){
            mp[inorder[i]] = i;
        }
        
        return buildTreeFromPostorder(0,postorder.size()-1,postorder);
    }
};