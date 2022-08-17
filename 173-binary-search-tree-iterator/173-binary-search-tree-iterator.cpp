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
class BSTIterator {
public:
    TreeNode* head = new TreeNode(-1);
    TreeNode* curr;
    void inorder(TreeNode* node){
        if(node->left)
            inorder(node->left);
        
        curr->right = node;
        curr = curr->right;
        
        if(node->right)
            inorder(node->right);
    }
    BSTIterator(TreeNode* root) {
        
        head->right = root;
        curr = head;
        inorder(root);
    }
    
    int next() {
        head = head->right;
        return head->val;
    }
    
    bool hasNext() {
        return (head->right != NULL);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */