class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        long long sum = 0;
        vector<int> results(nums.size(),-1);
        if(k > nums.size() || 2*k >= nums.size()) return results;
        for(int i=0;i<=min(2*k,(int)nums.size());++i){
            sum += nums[i];
        }
        
        int left = 0;
        int right = 2*k + 1;
        for(int i=k;i<(int)nums.size()-(int)k;++i){
            results[i] = sum/(2*k + 1);
            if(left >= 0)
                sum -= nums[left];
            if(right < nums.size())
                sum += nums[right];
            left++;
            right++;
        }
        return results;
    }
};