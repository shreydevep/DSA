class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        vector <int> temp;
        for(int i=(nums.size()-k);i<nums.size();++i){
            temp.push_back(nums[i]);
        }
        int end = nums.size() - 1;
        int start = (nums.size()-k-1);
        while(start >= 0){
            swap(nums[start],nums[end]);
            start--;
            end--;
        }
        start = 0;
        for(auto x : temp){
            nums[start] = x;
            start++;
        }
        
    }
};