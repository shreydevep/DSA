class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int wrongPos = 0;
        vector<int> freq(26,0);
        for(int i=0;i<s1.length();++i){
           freq[(s1[i]-'a')]++;
            freq[(s2[i] - 'a')]--;
            if(s1[i] == s2[i]) continue;
            wrongPos++;
        }
        for(auto &x : freq) {
            if(x != 0) return false;
        }
        if(wrongPos <= 2) return true;
        return false;
    }
};