class Solution {
public:
    class Trie {
    struct Node{
        Node *links[26];
        bool flag = false;
        
        bool containsKey(char ch){
            return (links[ch -'a'] != NULL);
        }
        
        Node* get(char ch){
            return links[ch -'a'];
        }
        
        void put(char ch, Node* node){
            links[ch -'a'] = node;
        }
        
        void setEnd(){
            flag = true;
        }
        
        bool isEnd(){
            return flag;
        }
    };
    private: Node *root;
    public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node *node = root;
        for(auto ch : word){
            if(!node->containsKey(ch)){
                node->put(ch, new Node());
            }
            node = node->get(ch);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        Node *node = root;
        for(auto ch : word){
            if(!node->containsKey(ch)){
                return false;
            }
            node = node->get(ch);
        }
        if(node->isEnd()){
            return true;
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        Node *node = root;
        for(auto ch : prefix){
            if(!node->containsKey(ch)){
                return false;
            }
            node = node->get(ch);
        }
        return true;
    }
    void dfsWithPrefix(Node *node,string &word,vector<string> &res){
        if(res.size() == 3) return;
        if(node->flag){
            res.push_back(word);
        }
        for(char ch='a';ch<='z';++ch){
            if(node->containsKey(ch)){
                word += ch;
                dfsWithPrefix(node->get(ch),word,res);
                word.pop_back();
            }
        }
    } 
    vector<string> getCommonPrefix(string prefix){
        Node *node = root;
        vector<string> res;
        for(auto &ch : prefix){
            if(!node->containsKey(ch)){
                return res;
            }
            node = node->get(ch);
        }
        dfsWithPrefix(node,prefix,res);
        return res;
    }
};
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie *trie = new Trie();
        
        for(auto &product : products){
            trie->insert(product);
        }
        string prefix;
        vector<vector<string>> res;
        for(auto &ch : searchWord){
            prefix += ch;
            res.push_back(trie->getCommonPrefix(prefix));
        }
        return res;
        
        
    }
};