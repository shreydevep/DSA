class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        vector <int> res;
        for(int i=0;i<nums.size();++i) mp[nums[i]]++;
        for(auto x : mp){
            if(x.second > nums.size()/3) res.push_back(x.first);
        }
        return res;
    }
};