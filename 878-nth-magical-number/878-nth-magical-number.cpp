class Solution {
public:
    const int mod = 1e9 + 7;
    long long check(long long val,int a,int b){
        
        return ((val/(long long)a) + (val/(long long)b) - (val/(lcm((long long)a,(long long)b))));
    }
    int nthMagicalNumber(int n, int a, int b) {
        long long l = min(a,b);
        long long r = (long long)n*(long long)a*(long long)b;
        while(l <= r){
            long long mid = l + (r-l)/2;
            
            long long v1 = check(mid,a,b);
            if(v1 == n && (mid % a == 0 or mid % b == 0)){
                return mid % mod;
            }
            else if(v1 < n){
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        return -1;
    }
};