class Solution {
public:
    int getSetBit(int n){
        return __builtin_popcount(n);
    }
    int numSplits(string s) {
        
        vector<int> prefix(s.length()+1);
        vector<int> suffix(s.length()+1);
        prefix[0] = (1 << (s[0]-'a'));
        for(int i=1;i<s.length();++i){
            int temp = s[i] - 'a';
            prefix[i] = (prefix[i-1] | (1 << temp));
        }
        suffix[s.length()-1] = (1 << (s[s.length()-1] - 'a'));
        for(int i=s.length()-2;i>=0;--i){
            int temp = s[i] - 'a';
            suffix[i] = (suffix[i+1] | (1 << temp));
        }
        int ans = 0;
        for(int i=0;i<s.length()-1;++i){
            if(getSetBit(prefix[i]) == getSetBit(suffix[i+1])){
                ans++;
            }
        }
        return ans;
    }
};