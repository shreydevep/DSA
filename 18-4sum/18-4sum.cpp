class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        for(int i=0;i<nums.size();++i){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            
            int j = i + 1;
            for(int j=i+1;j<nums.size();++j){
                if(j > i+1 && nums[j] == nums[j-1]) continue;
                int k = j+1;
                int l = nums.size()-1;
                while(k < l){
                    if(nums[k] + nums[l] == (target-nums[i] - nums[j])){
                        res.push_back({nums[i],nums[j],nums[k],nums[l]});
                        int val1 = nums[k];
                        while(k < l && nums[k] == val1) k++;
                        
                        int val2 = nums[l];
                        while(k < l && nums[l] == val2) l--;
                    }
                    else if(nums[k] + nums[l] < (target - nums[i] - nums[j])){
                        k++;
                    }
                    else{
                        l--;
                    }
                    
                }
            }
        }
        return res;
    }
};