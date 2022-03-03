class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<int,int> freq;
        
        for(auto &x : s){
            freq[x]++;
        }
        bool odd = 0;
        int len = 0;
        for(auto &x : freq){
            len += (x.second/2);
            if(!odd && (x.second & 1)) odd = 1;
        }
        return (2*len + odd);
    }
};