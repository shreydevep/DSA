/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        
        vector<vector<int>> res;
        
        queue<Node*> q;
        if(root)
            q.push(root);
        int sz = q.size();
        while(!q.empty()){
            vector<int> temp;
            for(int i=0;i<sz;++i){
                auto node = q.front();
                q.pop();
                
                for(auto &child : node->children){
                    if(child) q.push(child);
                }
                temp.push_back(node->val);
            }
            sz = q.size();
            res.emplace_back(temp);
        }
        return res;
    }
};