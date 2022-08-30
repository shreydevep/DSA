class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int> dp(n,1);
        vector<int> par(n,-1);
        
        int ma=0,ind=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[j]%nums[i]==0){
                    if(dp[j]<=1+dp[i]){
                        dp[j]=1+dp[i];
                            par[j]=i;
                        
                        if(dp[j]>=ma){
                            ma=dp[j];
                            ind=j;
                        }
                    }
                    
                }
            }
        }
        vector<int> ans;
        // cout<<ind;
        while(ind!=-1){
            ans.push_back(nums[ind]);
            ind=par[ind];
        }
        return ans;
    }
};