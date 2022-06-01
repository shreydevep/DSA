class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int ans = nums.size();
        for(int i=0;i<nums.size();++i){
           
            while(nums[i] < nums.size() && nums[i] >= 0 && nums[i] != i && nums[nums[i]] != nums[i]){
                swap(nums[i],nums[nums[i]]);
            }
        }
        
        for(int i=0;i<nums.size();++i){
            if(nums[i] == ans) ans++;
            if(i == 0 or i == nums[i]) continue;
            return i;
        }
        return ans;
    }
};