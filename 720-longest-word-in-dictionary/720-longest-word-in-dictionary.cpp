class Solution {
public:
    class Trie{
        public:
            
            class Node{
                public:
                Node* links[26] = {NULL};
                bool flag = false;
                string str = "";
                
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
            bool search(string word){   
                Node* node = root;
               for(int i=0;i<word.length();++i){
                   if(!node->containsKey(word[i])){
                       return false;
                   }
                   node = node->get(word[i]);
                   if(!node->flag){
                       return false;
                   }
               }
                return node->flag;
                
            }
            
        
    };
    string longestWord(vector<string>& words) {
         Trie obj;
        string ans = "";
        for(auto word : words){
            obj.insert(word);   
        }
        for(auto word: words){
            if(obj.search(word)){
                if(ans.length() == word.length()){
                    if(ans > word){
                        ans = word;
                    }
                }
                else if(ans.length() < word.length()){
                    ans = word;
                }
            }
        }
        return ans;
    }
};