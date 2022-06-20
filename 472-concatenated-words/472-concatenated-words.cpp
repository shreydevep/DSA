class Solution {
public:
    class Trie{
        public:
            
            class Node{
                public:
                vector<Node*> links{26,{NULL}};
                bool flag = false;
                string str = "";
                Node(){
                    links.resize(26,{NULL});
                }
                bool containsKey(char ch){
                    return (links[ch-'a'] != NULL);
                }
                
                void put(char ch,Node* node){
                    links[ch-'a'] = node;
                }
                
                Node* get(char ch){
                    return links[ch-'a'];
                }
                
                
                void setEnd(string word){
                    flag = true;
                    str = word;
                }
                
                bool getEnd(){
                    return flag;
                }
            };
            Node* root;
            set <string> ans;
            Trie(){
                root = new Node();
            }
            
            void insert(string word){
                Node* node = root;
                for(int i=0;i<word.length();++i){
                    //cout << word[i] <<" "<< node->containsKey(word[i]) <<" ";
                    if(!node->containsKey(word[i])){
                        node->put(word[i],new Node);
                    }
                   // cout << node->get(word[i]) <<"\n";
                    node = node->get(word[i]);
                }
                node->setEnd(word);
                
                
            }
            void search(Node* curr,Node* nword){   
                if(curr->str != "" && nword->str != ""){
                    //Add to Hash Map
                    ans.insert(curr->str);
                }
                
                if(nword->str != ""){
                    search(curr,root);
                }
                
                for(int i=0;i<26;++i){
                    if(curr->links[i] != NULL && nword->links[i] != NULL){
                        search(curr->links[i], nword->links[i]);
                    }
                }
                
            }
            void searchPointer(Node* curr){
                if(curr->str != ""){
                    //Append new possible word
                    search(curr,root);
                }
                for(int i=0;i<26;++i){
                    if(curr->links[i] != NULL){
                        searchPointer(curr->links[i]);
                    }
                }
            }
        
        
    };
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        Trie obj;
        vector <string> fin;
       
        for(auto word : words){
            obj.insert(word);   
        }
        obj.searchPointer(obj.root);
        for(auto s : obj.ans){
            fin.push_back(s);
        }
        
        return fin;
    }
};