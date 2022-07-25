class Solution {
public:
    bool check(vector<int> &nums,int mid,int threshold){
        long long curr = 0;
        for(auto &x : nums){
            curr += (long long)((x+mid-1)/mid);
        }
        return (curr <= threshold);
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1;
        int r = 1e6 + 7;
        int ans = -1;
        while(l < r){
            int mid = (l+r)/2;
            if(check(nums,mid,threshold)){
                ans = mid;
                r = mid;
            }
            else{
                l = mid + 1;
            }
        }
        return ans;
        
        
    }
};