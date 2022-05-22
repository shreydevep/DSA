class Solution {
public:
     string recurr(int i,int j,string s){
        
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
        int ans = 0;
         pair<int,int> temp  = {0,0};
        for(int i=0;i<s.length();++i){
            for(int j=i;j<s.length();++j){
                if(dp[i][j]){
                   if(ans < (j-i+1)){
                       temp = {i,j};
                       ans = max(ans,j-i+1);
                   }
                }
            }
        }
         return s.substr(temp.first,temp.second-temp.first+1);
        
        
    }
    string longestPalindrome(string s) {
        return recurr(0,s.length()-1,s);  
    }
};