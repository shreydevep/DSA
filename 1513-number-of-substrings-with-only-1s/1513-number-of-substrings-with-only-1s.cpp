const int mod = 1e9 + 7;
class Solution {
public:
    int getSum(long long x){
        if(x % 2 == 0){
            return ((x/2) % mod * (x+1) % mod) % mod;
        }
        else{
            return (x % mod * ((x+1)/2) % mod) % mod;
        }
    }
    int numSub(string s) {
        int len = 0;
        int i = 0;
        int ans = 0;
        
        while(i < s.length()){
            if(s[i] == '0'){
                ans = (ans % mod + getSum(len) % mod) % mod;
                len = 0;
            }
            else{
                len++;
            }
            i++;
        }
         ans = (ans % mod + getSum(len) % mod) % mod;
        return ans;
    }
};