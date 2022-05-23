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
    TreeNode* getRightMostNode(TreeNode* leftNode,TreeNode* curr){
        //Curr Subtree LeftNode Right Most Node
        while(leftNode->right != NULL && leftNode->right != curr){
            leftNode = leftNode->right;
        }
        return leftNode;
    }
    vector<int> morrisPreorder(TreeNode* root){
        TreeNode* curr = root;
        vector<int> ans;
        while(curr != NULL){
            TreeNode* leftNode = curr->left;
             
            if(leftNode == NULL){
                //Process Current
                ans.push_back(curr->val);
                curr = curr->right;
            }else{
                TreeNode* rightMostNode = getRightMostNode(leftNode,curr);
                if(rightMostNode->right == NULL){
                    //Create Thread
                    ans.push_back(curr->val);
                    rightMostNode->right = curr;
                    curr = curr->left;
                }
                else{
                    //Break Thread
                    rightMostNode->right = NULL;
                    //ans.push_back(curr->val);
                    curr = curr->right;
                    
                }
                
            }
             
        }
        return ans;
    }
    vector<int> preorderTraversal(TreeNode* root) {
        return morrisPreorder(root);
    }
};