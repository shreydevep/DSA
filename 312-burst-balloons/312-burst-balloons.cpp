class Solution {
public:
    vector<vector<int>> dp;
    int recurr(int i,int j,vector<int> &nums){
            if(i > j) return 0;
            if(dp[i][j] != -1) return dp[i][j];
        
            int curr = INT_MIN;
            for(int k=i;k<=j;++k){
                int temp = (nums[i-1]*nums[k]*nums[j+1]) + recurr(i,k-1,nums) + recurr(k+1,j,nums);
                curr = max(curr,temp);
            }
            
            return dp[i][j] = curr;
    }
   
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        dp.resize(nums.size()+1,vector<int>(nums.size()+1,-1));
        return recurr(1,nums.size()-2,nums);
    }
};