class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> freq(26,0);
        for(auto x : s){
            freq[x-'a']++;
        }
        
        for(auto y : t){
            freq[y-'a']--;
        }
        
        for(int i=0;i<26;++i){
            if(freq[i] < 0) return (i + 'a');
        }
        return 'a';
    }
};