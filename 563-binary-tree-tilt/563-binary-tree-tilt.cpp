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
    pair<int,int> tilt(TreeNode* root){
        if(!root) return {0,0};
        
        auto leftChild = tilt(root->left);
        auto rightChild = tilt(root->right);
        return {leftChild.first + rightChild.first + root->val,abs(leftChild.first-rightChild.first) + leftChild.second + rightChild.second};
    }
    int findTilt(TreeNode* root) {
        return tilt(root).second;
    }
};