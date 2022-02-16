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
    int ans = 0;
    int postorder(TreeNode* node){
        if(node == NULL) return 1;
        else if(node->left == NULL && node->right == NULL) return -1;
        
        int leftNode = postorder(node->left);        
        int rightNode = postorder(node->right);
        if(leftNode == -1 || rightNode == -1){
            ans++;
            return 0;
        }
        else if(leftNode == 0 || rightNode == 0){
            return 1;
        }
        else if(leftNode == 1 && rightNode == 1){
            return -1;
        }
        
        return 0;
        
        
    }
    int minCameraCover(TreeNode* root) {
        //PostOrder
        int rootNode = postorder(root);
        if(rootNode == -1){
            ans++;
        }
        return ans;
        
    }
};