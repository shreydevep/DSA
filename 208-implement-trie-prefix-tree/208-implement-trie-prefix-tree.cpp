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
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */