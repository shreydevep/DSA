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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int sz = q.size();
        vector<double> res;
        while(!q.empty()){
            double sum = 0.0;
            for(int i=0;i<sz;++i){
                auto node = q.front();
                q.pop();
                sum += (double)node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            
            res.push_back(sum/(double)sz);
            sz = q.size();
        }
        return res;
    }
};