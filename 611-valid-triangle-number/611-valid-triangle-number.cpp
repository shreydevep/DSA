class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        
        //Sum of two sides greater the third
        sort(nums.begin(),nums.end());
        int ans = 0;
        for(int i=0;i<nums.size();++i){
            for(int j=i+1;j<nums.size();++j){
                
                auto itr =lower_bound(nums.begin()+j+1,nums.end(),nums[i] + nums[j]);
                    ans += (itr - nums.begin()-j-1);
            }
        }
        return ans;
        
    }
};