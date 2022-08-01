class Solution {
public:
    vector<vector<int>> res;
    void genPer(vector<int> &nums,vector<int> &permutation,vector<bool> &visitedIndex){
        if(permutation.size() == nums.size()){
            res.push_back(permutation);
            return;
        }
        for(int pos=0;pos<visitedIndex.size();++pos){
            if(visitedIndex[pos] or (pos > 0 && nums[pos] == nums[pos-1] && !visitedIndex[pos-1])) continue;
            
            visitedIndex[pos] = true;
            permutation.push_back(nums[pos]);
            genPer(nums,permutation,visitedIndex);
            permutation.pop_back();
            visitedIndex[pos] = false;
        }
        
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> permutation;
        vector<bool> visitedIndex(nums.size(),0);
        genPer(nums,permutation,visitedIndex);
        return res;
        
    }
};