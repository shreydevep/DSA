class Solution {
public:
    int subarraysWithAtmostK(vector<int>& nums,int k){
        if(k <= 0) return 0;
        unordered_map<int,int> freq;
        int count = 0;
        int i = 0;
        int ans = 0;
        for(int j=0;j<nums.size();++j){
            freq[nums[j]]++;
            while(freq.size() > k && i < j){
                freq[nums[i]]--;
                if(freq[nums[i]] == 0){
                    freq.erase(nums[i]);
                }
                i++;
            } 
            ans += (j-i+1);
        }
        
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarraysWithAtmostK(nums,k) - subarraysWithAtmostK(nums,k-1);
    }
};
