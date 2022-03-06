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
const int N = 1e5 + 1;
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        vector<TreeNode*> mp(N);
        vector<bool> st(N);
        for(int i=0;i<N;++i){
            mp[i] = NULL;
            st[i] = 0;
        }
        
        
        for(auto node : descriptions){
            TreeNode* par = NULL;
            if(mp[node[0]] != NULL){
                par = mp[node[0]];
            }else{
                par = new TreeNode;
                par->val = node[0];
                mp[node[0]] = par;
            }
           
           
            if(node[2] == 1){
                TreeNode* leftChild = NULL;
                if(mp[node[1]] != NULL){
                    leftChild = mp[node[1]];
                }else{
                    leftChild = new TreeNode;
                    leftChild->val = node[1];
                    mp[node[1]] = leftChild;
                }
                st[node[1]] = 1;
                par->left = leftChild;
            }else{
                TreeNode* rightChild = NULL;
                if(mp[node[1]] != NULL){
                    rightChild = mp[node[1]];
                }else{
                    rightChild = new TreeNode;
                    rightChild->val = node[1];
                    mp[node[1]] = rightChild;
                }
                st[node[1]] = 1;
                par->right = rightChild;
            }
        }
        
        TreeNode* root = NULL;
        for(int i=0;i<N;++i){
              //cout << i <<" "<< st[i] <<"\n";
            if(st[i] == 0 && mp[i] != NULL){
               
            root = mp[i];
               
            break;
            }
        }
        return root;
    }
};