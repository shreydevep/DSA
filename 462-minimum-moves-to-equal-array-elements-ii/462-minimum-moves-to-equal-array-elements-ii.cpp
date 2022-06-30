class Solution {
public:
    int minMoves2(vector<int>& nums) {
        if(nums.size() <= 1) return 0;
        sort(nums.begin(),nums.end());
        
        int median1 = nums[nums.size()/2];
        int median2 = nums[(nums.size()+1)/2];
        int ans1 = 0;
        int ans2 = 0;
        
        for(int i=0;i<nums.size();++i){
            ans1 += abs(nums[i]-median1);
            ans2 += abs(nums[i]-median2);
        }
        
        return min(ans1,ans2);
    }
};