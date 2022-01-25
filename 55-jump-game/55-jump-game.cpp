class Solution {
public:
    
    bool canJump(vector<int>& nums) {
        int mx = nums[0];
        int i=0;
        for(i=1;i<nums.size() && i <= mx;++i){
            mx = max(mx,nums[i]+i);
        }
        //cout << i <<"\n";
        return (i == nums.size());
        
        
    }
};