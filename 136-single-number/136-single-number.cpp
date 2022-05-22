class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xx = 0;
        for(auto &x : nums) xx^= x;
        return xx;
    }
};