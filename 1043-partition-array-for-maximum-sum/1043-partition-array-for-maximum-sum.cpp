class Solution {
public:
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        
        vector<int> dp(arr.size()+1,0);
        
        
        dp[0] = 0;
        for(int i=1;i<=arr.size();++i){
            int cnt = k;
            int j = i;
            int maxEle = arr[i-1];
            while(cnt-- && j >= 1){
                //cout << i <<" "<< j <<" ";
                maxEle = max(maxEle,arr[j-1]);
                dp[i] = max(dp[i],(i-j+1)*maxEle + dp[j-1]) ;
                j--;
            }
            //cout <<"\n";
        }
        
       
        
        return dp[arr.size()];
        
        
        
    }
};