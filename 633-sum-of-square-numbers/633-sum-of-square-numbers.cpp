class Solution {
public:
    bool check(long long x){
        long long y = sqrt(x);
        if(y*y == x) return true;
        return false;
    }
    bool judgeSquareSum(int c) {
        for(long long i=0;i*i<=c;++i){
            long long a = i*i;
            long long b = c - a;
            if(check(b)) return true;
        }
        return false;
    }
};