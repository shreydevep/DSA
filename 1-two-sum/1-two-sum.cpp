class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int s) {
        map<int,int> mp;
        vector <int> res;
        for(auto x : nums){
            mp[x]++;
        }
        
        for(int i=0;i<nums.size();++i){
            mp[nums[i]]--;
            
            if(mp.find(s-nums[i]) != mp.end() && mp[s-nums[i]] > 0){
                res.push_back(i);
                for(int j=0;j<nums.size();++j){
                    if(nums[j] == s-nums[i] && j != i){
                        res.push_back(j);
                        break;
                    }
                }
                break;
            }
        }
        return res;
    }
};