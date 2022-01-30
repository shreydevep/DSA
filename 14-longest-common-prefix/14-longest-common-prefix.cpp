class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0 || strs[0].length() == 0 ) return "";
        string prefix;
        for(int j=0;j<200;++j){
                int cnt = 0;
                for(auto x : strs){
                    if(x.length() >= j && x[j] == strs[0][j]){
                        cnt++;
                    }
                    else{
                        return prefix;
                    }
                
            }
            if(cnt == strs.size() && j < strs[0].length()) prefix += strs[0][j];
            
            
        }
        return prefix;
    }
};