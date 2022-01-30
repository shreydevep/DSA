class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        
        int len = nums.size() - k;
        reverse(nums.begin(),nums.begin() + len);
        reverse(nums.begin()+k,nums.begin()+len);
        
        int start = 0;
        int end = nums.size()-1;
        for(int i=0;i<k;++i){
            swap(nums[start],nums[end]);
            start++;
            end--;
            if(start > end){
                break;
            }
        }
        reverse(nums.begin(),nums.begin()+k);
        
        
    }
};