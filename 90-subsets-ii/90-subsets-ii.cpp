class Solution {
public:
    vector<vector<int>> res;
    void recurr(int i,vector<int> &posSet,vector<int> &nums){
        res.push_back(posSet);
        if(i >= nums.size()){
            return;
        }
        for(int next_i = i;next_i<nums.size();++next_i){
            if(next_i > i && (nums[next_i] == nums[next_i-1])) continue;
            posSet.push_back(nums[next_i]);
            recurr(next_i+1,posSet,nums);
            posSet.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> posSet;
        recurr(0,posSet,nums);
        return res;
    }
};