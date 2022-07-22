class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0;
        int sum = 0;
        int ans = INT_MAX;
        for(int j=0;j<nums.size();++j){
            sum += nums[j];
            while(i <= j && sum >= target){
                
                ans = min(ans,j-i+1);
                sum -= nums[i];
                i++;
            }
        }
        
        return (ans != INT_MAX) ? ans : 0;
    }
};