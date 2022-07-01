class Solution {
public:
    vector<vector<bool>> recurr(int i,int j,string s){
        
        vector<vector<bool>> dp(s.length(),vector<bool> (s.length(),0));
        int cnt = 0;
        for(int i=0;i<s.length();++i){
            dp[i][i] = 1;
        }
        cnt++;
        for(int i=0;i<s.length()-cnt;++i){
            dp[i][i+1] = (s[i] == s[i+1]);
        }
        cnt++;
        for(int dig=2;dig<s.length();++dig){
            for(int i=0;i<s.length()-cnt;++i){
                int j = i + dig;
                
                dp[i][j] = dp[i+1][j-1] and (s[i] == s[j]);
            }
            cnt++;
        }
        return dp;
        
        
    }
    
    bool checkPartitioning(string s) {
        vector<vector<bool>> dp;
        dp = recurr(0,s.length()-1,s);
        
        for(int i=0;i<s.length()-2;++i){
            for(int j=i+1;j<s.length()-1;++j){
               if(dp[0][i] && dp[i+1][j] && dp[j+1][s.length()-1]) return true;
            }
        }
        return false;
    }
};