class Solution {
public:
    static bool compare(vector<int> &v1,vector<int> &v2){
        if(v1[0] == v2[0]){
            if(v1[1] < v2[0]){
                return 1;
            }
        }
        else if(v1[0] < v2[0]) return 1;
        return 0;
    }
    
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),compare);
        
        vector<int> dp(pairs.size()+1,1);
        for(int i=0;i<pairs.size();++i){
            for(int j=0;j<i;++j){
                if(pairs[j][1] < pairs[i][0]){
                    dp[i] = max(dp[j]+1,dp[i]);
                }
            }
        }
        return dp[pairs.size()-1];
        
    }
};