class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26,0);
        for(auto &x : s) freq[x-'a']++;
        unordered_set<int> st;
        
        int ans = 0;
        for(int i=0;i<26;++i){
            while(freq[i] && st.find(freq[i]) != st.end()){
                freq[i]--;
                ans++;
            }
            st.insert(freq[i]);
        }
        
        return ans;
    }
};