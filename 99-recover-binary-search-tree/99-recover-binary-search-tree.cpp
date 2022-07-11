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
    TreeNode* node1 = NULL;
    TreeNode* node2 = NULL;
    TreeNode* prevEle = NULL;
    void recurr(TreeNode* node){
        if(!node) return;
        recurr(node->left);
        if(node1 == NULL && ((prevEle == NULL || prevEle->val >= node->val))){
            node1 = prevEle;
        }
        if(node1 != NULL && (prevEle->val >= node->val)){
            node2 = node;
        }
        prevEle = node;
        recurr(node->right);
        
    }
    void recoverTree(TreeNode* root) {
         recurr(root);
         if(node1 != NULL && node2 != NULL){
             int temp = node1->val;
             node1->val = node2->val;
             node2->val = temp;
            return;
        }
        
        
    }
};