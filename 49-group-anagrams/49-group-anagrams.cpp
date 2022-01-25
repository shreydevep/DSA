class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> hash;
        for(auto x : strs){
            string temp = x;
            sort(temp.begin(),temp.end());
            hash[temp].push_back(x);
        }
        vector<vector<string>> res;
         res.reserve(hash.size());
        for(auto x : hash){
            res.push_back(std::move(x.second));
        }
        return res;
        
    }
};