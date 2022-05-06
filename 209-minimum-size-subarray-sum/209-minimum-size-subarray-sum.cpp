class Solution {
public:
    
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0;
        int sum = 0;
        int ans = INT_MAX;
       for(int j = 0;j<nums.size();++j){
            sum += nums[j];
           while(sum >= target){
               ans = min(ans,j+1 - i);
               sum -= nums[i++];
           }
       }
        return (ans != INT_MAX) ? ans : 0;
    }
};