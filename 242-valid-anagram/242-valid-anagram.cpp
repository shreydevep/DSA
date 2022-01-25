class Solution {
public:
    bool isAnagram(string s, string t) {
        vector <int> freq(26,0);
        for(auto x : s){
            freq[x-'a']++;
        }
        for(auto y : t){
            freq[y-'a']--;
        }
        
        for(auto x : freq){
            if(x != 0){
                return false;
            }
        }
        
        return true;
    }
};