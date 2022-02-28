class WordDictionary {
public:
    struct Node{
        Node* links[26] = {NULL};
        bool flag = false;
        
        bool containsKey(char ch){
            return (links[ch-'a'] != NULL);
        }
        
        void put(char ch,Node* node){
            links[ch-'a'] = node;
        }
        Node* get(char ch){
            return links[ch-'a'];
        }
        void setEnd(){
            flag = true;
        }
        
        bool getEnd(){
            return flag;
        }
    };
    Node* root;
    WordDictionary() {
        root = new Node;    
    }
    
    void addWord(string word) {
        Node* node = root;
        for(int i=0;i<word.length();++i){
            
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node);
            }
            node = node->get(word[i]);
        }
        node->setEnd();
        
       
    }
    bool ans = false;
    void dfs(Node* node,string &word, int i){
         if(i == word.length() && word[i] == '.'){
            ans |= true;
            return;
        }
        if(i == word.length()){
            
               ans |= node->getEnd();   
               return;
        }
        if(word[i] != '.' && !node->containsKey(word[i])){
            return;
        }
       
        
        if(word[i] == '.'){
            for(char ch='a';ch<='z';++ch){
                if(node->containsKey(ch)){
                    
                    dfs(node->get(ch),word,i+1);
                }
            }
            return;
        }
        else{
            if(!node->containsKey(word[i])){
                return;
            }
            dfs(node->get(word[i]),word,i+1);
        }
        
    }
    bool search(string word) {
        ans = false;
        Node* node = root;
        dfs(node,word,0);
        return ans;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */