class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> freq(26,101);
        
        for(auto s : words){
            vector<int> cnt(26,0);
            
            for(auto x : s){
                cnt[x - 'a']++;
            }
            for(int i=0;i<26;++i){
                freq[i] = min(freq[i],cnt[i]);
            }
        }
        vector<string> ans;
        for(int i=0;i<26;++i){
            string temp;
            temp += (i + 'a');
            int times = freq[i];
            while(times--) ans.push_back(temp);
        }
        return ans;
        
        
    }
};