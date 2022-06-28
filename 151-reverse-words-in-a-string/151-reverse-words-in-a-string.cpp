class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string res;
        string word;
        while(ss >> word){
            reverse(word.begin(),word.end());
            res += (word + " "); 
        }
        res.pop_back();
        reverse(res.begin(),res.end());
        return res;
    }
};