class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(auto &x : nums){
            if(nums[abs(x)] < 0){
                return abs(x);
            }
            nums[abs(x)] *= -1;
        }
       
        return -1;
    }
};