class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<long long> bits(33,0);
        long long neg = 0;
        for(auto &x: nums){
            long long temp = abs(x);
            if(x < 0) neg++;
            for(int i=0;i<32;++i){
                    bits[i] += (temp & (1ll << i));
            }
        }
        
        long long fin = 0;
        for(int i=0;i<32;++i){
            if(bits[i] % 3 != 0){
                fin += (1 << i);
            }
        }
        if(neg % 3 != 0) fin = -1*fin;
        return fin;
    }
};