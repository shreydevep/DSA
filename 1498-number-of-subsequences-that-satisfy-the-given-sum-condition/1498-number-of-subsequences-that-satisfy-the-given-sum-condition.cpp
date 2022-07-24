class Solution {
public:
    int mod = 1e9 + 7;
    long long binary_expo(long long a, long long b, long long m) {
        a %= m;
        long long res = 1;
        while (b > 0) {
            if (b & 1)
                res = res * a % m;
            a = a * a % m;
            b >>= 1;
        }
        return res;
}
    
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int i = 0;
        int j = nums.size()-1;
        int total = 0;
        while(i <= j){
            if(nums[i] + nums[j] <= target){
                int len = j-i;
                int pws = binary_expo(2,len,mod);
                
                total = (total % mod + pws % mod ) % mod;
                i++;
            }
            else{
                if(2*nums[j] <= target) total++;
                j--;
            }
        }
        return total;
    }
};

