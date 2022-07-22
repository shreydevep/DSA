class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int> mp;
        int ans = 0;
        int i =0;
        for(int j=0;j<s.length();++j){
            mp[s[j]]++;
            while(i <= j && mp['a'] > 0 && mp['b'] > 0 && mp['c'] > 0){
                
                ans += (s.length()-j);
                mp[s[i]]--;
                i++;
            }
        }
        return ans;
    }
};
