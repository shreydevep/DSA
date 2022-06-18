class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> prefix(nums.size()+2,0);
        for(int i=1;i<=nums.size();++i){
            prefix[i] = prefix[i-1] + nums[i-1];
        }
        
        
        for(int i=1;i<=nums.size();++i){
           
            if(prefix[i-1] == (prefix[nums.size()]-prefix[i])){
                
                return (i-1);
            }
        }
        return -1;
    }
};