class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        multiset<char> st;
        for(auto &ch : magazine){
            st.insert(ch);
        }
        for(auto &ch : ransomNote){
            if(st.find(ch) == st.end()){
                return false;
            }
            st.erase(st.find(ch));
        }
        return true;
        
    }
};