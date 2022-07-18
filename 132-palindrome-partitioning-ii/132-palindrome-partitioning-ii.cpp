class Solution {
public:
    bool isPalindrome(string &s, int start, int end) {
        
        while(start < end) {
            
            if(s[start] != s[end]) return false;
            
            start += 1;
            end -= 1;
            
        }
        
        return true;
        
    }
    int mcm(vector<vector<int>> &dp,string &s,int i,int j){
        if(i >= j){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(isPalindrome(s,i,j)){
            return dp[i][j] = 0;
        }
        int temp_ans = INT_MAX;
        for(int k=i;k<j;++k){
            if(!isPalindrome(s,i,k)){
                continue;
            }
            int left;
            if(dp[i][k] != -1){
                left = dp[i][k];
            }
            else{
                left =  mcm(dp,s,i,k);
            }
            int right;
            if(dp[k+1][j] != -1){
                right = dp[k+1][j];
            }
            else{
                right =  mcm(dp,s,k+1,j);
            }
            
            temp_ans = min(temp_ans,(1 +left + right));
        }
        return dp[i][j] = temp_ans;
    }
    
    int minCut(string s) {
      vector<int> dp(s.length()+1,0);
      dp[s.length()] = 0;
      for(int i=s.length()-1;i>=0;i--){
          int cost = INT_MAX;
          for(int j=i;j<s.length();++j){
              if(isPalindrome(s,i,j))
                cost = min(cost,dp[j+1]+1);
          }
          dp[i] = cost;
      }
        return dp[0]-1;
    }
};