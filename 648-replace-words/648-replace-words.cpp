class Solution {
public:
    class Trie{
        public:
        class Node{
            public:
            Node* links[26] = {NULL};
            string str = "";
            
            bool containsKey(char ch){
                return (links[ch-'a'] != NULL);
            }
            void put(char ch, Node* node){
                links[ch-'a'] = node;
            }
            
            Node* get(char ch){
                return links[ch-'a'];
            }
            
            void setEnd(string word){
                str = word;
            }
        };
        Node* root;
        Trie(){
            root = new Node();
        }
        
        void insert(string word){
            Node* node = root;
                for(auto ch : word){
                    if(!node->containsKey(ch)){
                        node->put(ch,new Node);
                    }
                    node = node->get(ch);
                }
            node->setEnd(word);
        }
        string replaceWithPrefix(string word){
            Node* node = root;
            for(auto ch : word){
                
                if(!node->containsKey(ch)){
                    return word;
                }
                
                
                node = node->get(ch);
                //cout << ch <<" "<< node->str <<" "<< word <<"\n";
                if(node->str != ""){
                    return node->str;
                }
               
            }
            if(node->str != "") return node->str;
            return word;
        }
        
    };
    vector<string> removeDupWord(string str)
    {
    // Used to split string around spaces.
        vector <string> fin;
        istringstream ss(str);
  
        string word; // for storing each word
  
    // Traverse through all words
    // while loop till we get 
    // strings to store in string word
        while (ss >> word) 
        {
            // print the read word
            fin.push_back(word);
        }
        return fin;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie obj;
        
        vector <string> fin = removeDupWord(sentence);
        for(auto word : dictionary){
            
            obj.insert(word);
            
        }
        for(int i=0;i<fin.size();++i){
            fin[i] = obj.replaceWithPrefix(fin[i]);
        }
        
        sentence = "";
        for(int i=0;i<fin.size();++i){
            sentence += (fin[i] + " ");
        }
        sentence.pop_back();
        return sentence;
    }
};