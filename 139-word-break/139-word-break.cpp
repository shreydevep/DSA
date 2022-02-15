class Solution {
public:
    set <string> dict;
    bool isPresent(string s){
        if(dict.find(s) == dict.end()) return 0;
        return 1;
    }
    void mcm(int i,int j,string &s,vector<vector<bool>> &dp){    
        dp[i][j] = (dp[i][j] || isPresent(s.substr(i,j-i+1)));
        //cout << isPresent(s.substr(i,j-i+1)) <<" "<< s.substr(i,j-i+1) <<"\n";
        for(int k=i;k<j;++k){
            // break
           // cout << i <<" "<< k <<" "<< k+1 <<" "<< j <<"\n";
            dp[i][j] = (dp[i][j] || (dp[i][k] && dp[k+1][j]));
        }
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        for(auto x : wordDict) dict.insert(x);
        vector<vector<bool>> dp(s.length()+1,vector<bool>(s.length()+1,0));
        for(int len=0;len<s.length();++len){
            for(int i=0;i<s.length()-len;++i){
                int j = i + len;
                //cout << i <<" "<< j <<"\n";
                mcm(i,j,s,dp);
            }
        }
        return dp[0][s.length()-1];
    }
};