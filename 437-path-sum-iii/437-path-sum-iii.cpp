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
    unordered_map<long long,long long> hash;
    int total = 0;
    void recurr(TreeNode* root,long long sumUptoRoot,int target){
        if(root==NULL) return;
        
        sumUptoRoot += root->val;
        if(hash.find(sumUptoRoot - target) != hash.end()){
            total += hash[sumUptoRoot - target];
        }
        hash[sumUptoRoot]++;
        recurr(root->left,sumUptoRoot,target);
        recurr(root->right,sumUptoRoot,target);
        hash[sumUptoRoot]--;
    }
    int pathSum(TreeNode* root, int targetSum) {
        hash[0]++;
        recurr(root,0ll,targetSum);
        return total;
    }
};