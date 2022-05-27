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
    TreeNode* build(int psi,int pei,int ppsi,int ppei,vector<int> &preorder){
        if(psi > pei) return NULL;
        TreeNode* root = new TreeNode();
        root->val = preorder[psi];
        if(psi == pei) return root;
        int idx = mp[preorder[psi+1]];
        int tnel = idx - ppsi + 1;
        root->left = build(psi+1,psi+tnel,ppsi,idx,preorder);
        root->right = build(psi + tnel + 1,pei,idx + 1,ppei - 1,preorder);
        return root;
    }
    unordered_map<int,int> mp;
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        for(int i=0;i<postorder.size();++i){
            mp[postorder[i]] = i;
        }
        return build(0,preorder.size()-1,0,postorder.size()-1,preorder);
        
    }
};