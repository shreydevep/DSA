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
    int solve(TreeNode* node,bool canBreak,map<pair<TreeNode*,int>,int> &dp){
        if(node == NULL) return 0;
        if(dp.find({node,canBreak}) != dp.end()) return dp[{node,canBreak}];
        
        int breakCurr = node->val + solve(node->left,0,dp) + solve(node->right,0,dp);
        
        int notBreakCurr = solve(node->left,1,dp) + solve(node->right,1,dp);
        
        if(canBreak){
            
            return dp[{node,canBreak}] = max(breakCurr,notBreakCurr);
        }
        else{
            
            return dp[{node,canBreak}] = notBreakCurr;
            
        }
    }
    int rob(TreeNode* root) {
        if(root == NULL) return 0;
        map<pair<TreeNode*,int>,int> dp;
        return max((solve(root->left,1,dp) + solve(root->right,1,dp)),(solve(root->left,0,dp) + solve(root->right,0,dp)) + root->val);   
    }
};