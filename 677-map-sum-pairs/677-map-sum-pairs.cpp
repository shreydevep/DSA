class MapSum {
public:
        class Node{
            public:
            Node* links[26] = {NULL};
            int val = 0;
            
            bool containsKey(char ch){
                return (links[ch-'a'] != NULL);
            }
            void put(char ch, Node* node){
                links[ch-'a'] = node;
            }
            
            Node* get(char ch){
                return links[ch-'a'];
            }
            
            void setEnd(int v){
                val = v;
            }
        };
        Node* root;
        MapSum(){
            root = new Node();
        }
        
    
    void insert(string word, int val) {
        Node* node = root;
                for(auto ch : word){
                    if(!node->containsKey(ch)){
                        node->put(ch,new Node);
                    }
                    node = node->get(ch);
                }
            node->setEnd(val);
    }
    void recurr(int &total,Node* curr){
        if(curr == NULL) return;
        
        total += curr->val;
        for(int i=0;i<26;++i){
            recurr(total,curr->links[i]);
        }
    }
    int sum(string prefix) {
        Node* node = root;
        int total = 0;
        for(auto ch : prefix){
            if(!node->containsKey(ch)){
                return 0;
            }
            node = node->get(ch);
        }
       
            recurr(total,node);
        
        
        return total;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */