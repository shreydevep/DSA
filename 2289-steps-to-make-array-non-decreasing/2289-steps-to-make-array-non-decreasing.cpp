class Solution {
public:
    int totalSteps(vector<int>& nums) {
        vector<int> dp(nums.size(),0);
        stack<int> st;
        for(int i=nums.size()-1;i>=0;--i){
            int cnt = 0;
            while(!st.empty() && nums[st.top()] < nums[i]){
                dp[i] = max(dp[i]+1,dp[st.top()]);
                st.pop();
            }
            st.push(i);
        }
        int ans = 0;
        for(int i=0;i<nums.size();++i){
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};

    
    
                       