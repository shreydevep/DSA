class Solution {
public:
    int subarraywithAtmostK(vector<int> &nums,int k){
        int odd = 0;
        int even = 0;
        int ans = 0;
        int i = 0;
        for(int j=0;j<nums.size();++j){
            if(nums[j] % 2 == 0) even++;
            else odd++;
            while(i <= j && odd > k){
                if(nums[i] % 2 == 0) even--;
                else odd--;
                i++;
            }
            ans += (j-i+1);
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return subarraywithAtmostK(nums,k) - subarraywithAtmostK(nums,k-1);
    }
};