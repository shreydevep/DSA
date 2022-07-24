class Solution {
public:
    int mySqrt(int x) {
        int l = 1;
        int h = INT_MAX;
        long long m;
        int ans = 1;
        if(x == 0){
            return 0;
        }
        while(l <= h){
            m = l + (h-l)/2;
            if(m*m <= x){
                ans = m;
                l = m+1;
            }
            else{
                h = m-1;
            }
        }
        return ans;
    }
};