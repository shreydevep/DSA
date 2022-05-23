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
    
    pair<int, int> dfs(TreeNode* root) {
        if(!root) return {0, 0};
        auto [leftDontRob, leftRob]   = dfs(root -> left);
        auto [rightDontRob, rightRob] = dfs(root -> right);
        return {
            max(leftDontRob, leftRob) + max(rightDontRob, rightRob),
            root -> val + leftDontRob + rightDontRob
        };
    }
    int rob(TreeNode* root) {
        auto ans = dfs(root);
        return max(ans.first,ans.second);
    }
};