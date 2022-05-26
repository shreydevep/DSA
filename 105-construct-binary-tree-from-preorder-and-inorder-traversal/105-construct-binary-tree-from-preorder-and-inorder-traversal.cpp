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
    TreeNode* buildTreeFromPreorder(vector<int>& preorder,vector<int> &inorder){
        
        if(inorder.size() == 0) return NULL;
        
        vector<int> leftSubTree;
        vector<int> rightSubTree;
        bool flag = 0;
        
        for(int j = 0;j<inorder.size();++j){
            if(inorder[j] == preorder[rt]){
                flag = 1;
                continue;
            }
            if(!flag){
                leftSubTree.push_back(inorder[j]);
            }
            else{
                rightSubTree.push_back(inorder[j]);
            }
        }
        TreeNode* root = new TreeNode();
        root->val = preorder[rt];
        rt++;
        root->left = buildTreeFromPreorder(preorder,leftSubTree);
        root->right = buildTreeFromPreorder(preorder,rightSubTree);
        
        
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        rt = 0;
        TreeNode *head = buildTreeFromPreorder(preorder,inorder);
        return head;
    }
};