class Solution {
public:
    int getVal(string s){
        int res = 0;
        for(int i = s.length()-1;i>=0;--i){
            if(s[i] == '1')
                res += (1 << (s.length()-i-1));
        }
        return res;
    }
    
    bool hasAllCodes(string s, int k) {
        if(s.length() < k) return false;
        vector<bool> mp((1<<k),0);
        for(int i=0;i<s.length()-k + 1;++i){
            int val = getVal(s.substr(i,k));
            
            if(!mp[val]){
                mp[val] = true;
            }
        }
        int ans = true;
        for(int i=0;i<mp.size();++i){
            
            ans &= mp[i];
        }
        return ans;
        
    }
};