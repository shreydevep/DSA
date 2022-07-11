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
    unordered_map<int,int> mp;
    void travelInBST(TreeNode* node){
        if(!node) return;
        mp[node->val]++;
        travelInBST(node->left);
        travelInBST(node->right);
    }
    bool findTarget(TreeNode* root, int k) {
        travelInBST(root);
        
        for(auto &val : mp){
            int req = k - val.first;
            
            if(val.first == req){
                if(mp.find(req) != mp.end() && mp[req] > 1){
                    
                    return true;
                }
            }
            else{
                
                if(mp.find(req) != mp.end() && mp[req] > 0) return true;
            }
        }
        return false;
    }
};