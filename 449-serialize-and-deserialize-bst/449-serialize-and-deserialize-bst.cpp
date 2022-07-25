/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string preorder(TreeNode* root){
        if(root == NULL){
            return ((string)"null" + (string)",");
        }
        return (to_string(root->val)+","+ preorder(root->left) + preorder(root->right));
    }
    
    string serialize(TreeNode* root) {
        return preorder(root);
    }

    // Decodes your encoded data to tree.
    int rt = 0;
    TreeNode* build(vector<string> &v){
        
        if(rt >= v.size () || v[rt] == "null"){
            rt++;
            return NULL;
        }
        TreeNode* node = new TreeNode(stoi(v[rt]));
        rt++;
        node->left = build(v);
        node->right = build(v);
        return node;
    }
    TreeNode* deserialize(string data) {
        vector<string> v;
 
        stringstream ss(data);
        while (ss.good()) {
            string substr;
            getline(ss, substr, ',');
            v.push_back(substr);
        }
        
        return build(v);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;