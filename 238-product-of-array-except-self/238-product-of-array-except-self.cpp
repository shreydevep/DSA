class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector <int> prefix(n+2,1);
        vector <int> suffix(n+2,1);
        
        for(int i=1;i<=n;++i){
            prefix[i] *=(prefix[i-1]*nums[i-1]);
        }
        for(int i=n;i>=1;--i){
            suffix[i] *= (suffix[i+1]*nums[i-1]);
        }
        vector<int> res(n);
        for(int i=1;i<=n;++i){
            res[i-1] = prefix[i-1]*suffix[i+1]; 
        }
        return res;
    }
};