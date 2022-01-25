class Solution {
public:
    
    bool canJump(vector<int>& nums) {
        int mx = nums[0];
        for(int i=1;i<nums.size()-1;++i){
            if(i <= mx){
                mx = max(mx,nums[i]+i);
            }
        }
        if(nums.size()-1 <= mx){
            return 1;
        }
        else{
            return 0;
        }
        
    }
};