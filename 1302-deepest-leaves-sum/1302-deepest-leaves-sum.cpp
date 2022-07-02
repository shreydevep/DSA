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
    
    int recurr(TreeNode* root){
        queue<TreeNode*> q;
        int ans = 0;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            int temp = 0;
            for(int i=0;i<sz;++i){
                auto node = q.front();
                q.pop();
                temp += (node->val);
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            ans = temp;
        }
        return ans;
    }
    int deepestLeavesSum(TreeNode* root) {
        return recurr(root);
    }
};