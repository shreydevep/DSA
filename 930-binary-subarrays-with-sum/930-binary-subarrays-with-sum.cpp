class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        vector<int> prefix(nums.size(),0);
        prefix[0] = nums[0];
        unordered_map<int,int> mp;
        mp[prefix[0]]++;
        for(int i=1;i<nums.size();++i){
            prefix[i] = prefix[i-1] + nums[i];
            mp[prefix[i]]++;
        }
        int ans = 0;
        for(int i=0;i<nums.size();++i){
            mp[prefix[i]]--;
            if(prefix[i] == goal) ans++;
            int req = goal + prefix[i];
            ans += mp[req];
        }
        return ans;
    }
};