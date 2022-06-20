class Solution {
public:
  
    int minimumLengthEncoding(vector<string>& words) {
        set<string> st;
        for(auto &word : words){
            st.insert(word);
        }
        words.clear();
        for(auto word : st){
            words.push_back(word);
        }
        unordered_map<string,int> mp;
        
        for(auto word : words){
            reverse(word.begin(),word.end());
           
            for(int ln=1;ln<=word.length();++ln){
                
                if(mp.find(word.substr(0,ln)) != mp.end())
                    mp[word.substr(0,ln)]--;
                else
                    mp[word.substr(0,ln)] = 1;
            }
        }
        int ans = 0;
        for(auto word : words){
            reverse(word.begin(),word.end());
            if(mp[word] > 0){
                
                ans += (word.length()+1);
            }
        }
        return ans;
    }
};