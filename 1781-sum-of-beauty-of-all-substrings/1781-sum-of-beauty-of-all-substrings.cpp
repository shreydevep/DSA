class Solution {
public:
    int beautySum(string s) {
        int ans = 0;
        for(int i=0;i<s.length();++i){
            vector<int> freq(26,0);
            freq[s[i]-'a']++;
            
            for(int j=i+1;j<s.length();++j){
                freq[s[j]-'a']++;
                int mx = freq[s[i]-'a'];
                int mn = freq[s[i]-'a'];
                for(int k=0;k<26;++k){
                    if(freq[k] != 0)
                        mn = min(mn,freq[k]);
                    mx = max(mx,freq[k]);
                }
                ans += (mx-mn);
            }
        }
        return ans;
    }
};