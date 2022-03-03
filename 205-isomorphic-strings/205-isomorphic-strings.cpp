class Solution {
public:
    bool isIsomorphic(string s, string t) {
     
        map<char,char> mp;
        map<char,char> mpt;
        for(int i=0;i<s.length();++i){
            if(mp.find(s[i]) != mp.end() && mpt.find(t[i]) != mpt.end()){
                if(mp[s[i]] != t[i] || mpt[t[i]] != s[i]) return false;
            }
            else{
                if((mp.find(s[i]) == mp.end()) && (mpt.find(t[i]) == mpt.end())){
                   mp[s[i]] = t[i];
                   mpt[t[i]] = s[i];
                }
                else{
                    return false;
                }
                    
            }
        }
        return true;
    }
};