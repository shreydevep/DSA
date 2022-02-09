class Solution {
public:
    vector<pair<char,int>> compress(string s){
        vector<pair<char,int>> res;
        int curr = 0;
        int i = 0;
        while(i < s.length()){
            int cnt = 0;
            
            while(i < s.length() && i >= curr && s[curr] == s[i]){
                i++;
                cnt++;
            }
            
            res.push_back({s[curr],cnt});
            curr = i;
        }
        return res;
    }
    bool isLongPressedName(string name, string typed) {
        auto name_new = compress(name);
        auto typed_new = compress(typed);
        if(name_new.size() != typed_new.size()) return false;
        
        for(int i=0;i<name_new.size();++i){
            if(name_new[i].first == typed_new[i].first){
                if(name_new[i].second > typed_new[i].second){
                    return false;
                }
            }
            else{
                return false;
            }
        }
        return true;
    }
};