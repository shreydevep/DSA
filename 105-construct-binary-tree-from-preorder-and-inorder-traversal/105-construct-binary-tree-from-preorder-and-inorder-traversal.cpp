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
    TreeNode* buildTreeFromPreorder(int i,int j,vector<int>& preorder,vector<int> &inorder){
        
        if(j < i) return NULL;
        
        int k = mp[preorder[rt]];
        
        TreeNode* root = new TreeNode();
        root->val = preorder[rt];
        rt++;
        root->left = buildTreeFromPreorder(i,k-1,preorder,inorder);
        root->right = buildTreeFromPreorder(k+1,j,preorder,inorder);
        
        
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        rt = 0;
        for(int i=0;i<inorder.size();++i){
            mp[inorder[i]] = i;
        }
        
        TreeNode *head = buildTreeFromPreorder(0,inorder.size()-1,preorder,inorder);
        return head;
    }
};