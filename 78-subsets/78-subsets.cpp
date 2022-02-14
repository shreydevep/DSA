class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int sz = nums.size();
        vector <vector<int>> ans;
        for(int bit=0;bit<(1 << sz);++bit){
            vector <int> temp;
            for(int i=0;i<sz;++i){
                if(bit & (1 << i)){
                    temp.push_back(nums[i]);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};