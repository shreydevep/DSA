class Solution {
public:
    bool recurr(int i,int j,string &s,string &t){
        if(i == s.length() && j <= t.length()) return true;
        
        if(j >= t.length()) return false;
        
        
        if(s[i] == t[j]){
            return recurr(i+1,j+1,s,t);
        }
        else{
            return recurr(i,j+1,s,t);
        }
    }
    bool isSubsequence(string s, string t) {
        return recurr(0,0,s,t);
    }
};