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
    TreeNode* divideNconquer(int i,int j,vector<int>&nums){
        if(i > j) return NULL;
        if(i == j){
            return new TreeNode(nums[i]);
        }
        
        int mid = i + (j-i)/2;
        TreeNode *node = new TreeNode(nums[mid]);
        
        node->left = divideNconquer(i,mid-1,nums);
        node->right = divideNconquer(mid+1,j,nums);
        return node;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return divideNconquer(0,nums.size()-1,nums);
    }
};