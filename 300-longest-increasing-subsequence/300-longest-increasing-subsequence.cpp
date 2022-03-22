class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        vector<int> pseudo_lis;
        
        for(int i=0;i<nums.size();++i){
            auto itr = lower_bound(pseudo_lis.begin(),pseudo_lis.end(),nums[i]);
            if(itr == pseudo_lis.end()){
                pseudo_lis.push_back(nums[i]);
            }
            else{
                *itr = nums[i];
            }
        }
        return pseudo_lis.size();
    }
};