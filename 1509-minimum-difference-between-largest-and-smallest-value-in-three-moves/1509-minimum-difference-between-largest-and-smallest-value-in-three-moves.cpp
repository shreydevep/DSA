class Solution {
public:
    int minDifference(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums.size() <= 3) return 0;
        
        int ans = min(nums[nums.size()-4]-nums[0],nums[nums.size()-1] - nums[3]);
        ans = min(ans,nums[nums.size()-2] - nums[2]);
        ans = min(ans,nums[nums.size()-3] - nums[1]);
        return ans;
    }
};
