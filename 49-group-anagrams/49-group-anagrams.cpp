class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>,vector<string>> hash;
        
        for(auto x : strs){
            vector<int> freq(26,0);
            for(auto y : x){
                freq[y-'a']++;
            }
            hash[freq].push_back(x);
        }
        vector<vector<string>> res;
         res.reserve(hash.size());
        for(auto x : hash){
            res.push_back(std::move(x.second));
        }
        return res;
        
    }
};