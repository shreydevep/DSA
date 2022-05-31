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
    TreeNode* build(int i,int j,vector<int> &nums){
       if(i > j) return NULL;
        int pos = i;
        for(int k=i;k<=j;++k){
            if(nums[pos] < nums[k]){
                pos = k;
            }
        }
        TreeNode* node = new TreeNode(nums[pos]);
        
        node->left = build(i,pos-1,nums);
        node->right = build(pos+1,j,nums);
        return node;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return build(0,nums.size()-1,nums);
    }
};