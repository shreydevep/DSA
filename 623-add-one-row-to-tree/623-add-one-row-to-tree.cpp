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
    TreeNode* dfs(TreeNode* root,int depth,int val){
        if(depth == 1){
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        int sz = q.size();
        depth--;
        while(!q.empty()){
            if(depth == 1){
                for(int i=0;i<sz;++i){
                     auto node = q.front();
                     q.pop();
                    auto leftChild = node->left;
                    auto rightChild = node->right;
                    
                    TreeNode* left = new TreeNode(val);
                    TreeNode* right = new TreeNode(val);
                    
                    node->left = left;
                    node->right = right;
                    left->left = leftChild;
                    right->right = rightChild;
                }
                break;
            }
            for(int i=0;i<sz;++i){
                 auto node = q.front();
                 q.pop();
                 if(node->left)
                    q.push(node->left);
                 if(node->right)
                    q.push(node->right);
            }
            sz = q.size();
            depth--;
        }
        return root;
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        return dfs(root,depth,val);
    }
};