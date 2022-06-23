class Solution {
public:
   
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        int count = 0;
        int ans = 0;
        for(int i=0;i<(int)nums.size()-2;++i){
            int diff1 = nums[i+1] - nums[i];
            int diff2 = nums[i+2] - nums[i+1];
            
            if(diff1 == diff2){
                count++;
            }
            else{
                count = 0;
            }
            ans += count;
        }
        return ans;
        
    }
};