class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        
        
        
        int ans = nums.back() - nums[0];
        for(int i=0;i<nums.size()-1;++i){
            int mx = max(nums.back()-k,nums[i]+k);
            int mn = min(nums[0]+k,nums[i+1]-k);
            ans = min(ans,mx-mn);
        }
        return ans;
        
        
        
    }
};