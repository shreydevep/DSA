class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
       for(int i=0;i<nums.size();++i){
           if(nums[i] == 0) nums[i]--;
       }
        
        // unordered_map 'um' implemented
    // as hash table
    unordered_map<int, int> um;
    int sum = 0, maxLen = 0;
 
    // traverse the given array
    for (int i = 0; i < nums.size(); i++) {
 
        // accumulate sum
        sum += nums[i];
 
        // when subarray starts from index '0'
        if (sum == 0)
            maxLen = i + 1;
 
        // make an entry for 'sum' if it is
        // not present in 'um'
        if (um.find(sum) == um.end())
            um[sum] = i;
 
        // check if 'sum-k' is present in 'um'
        // or not
        if (um.find(sum) != um.end()) {
 
            // update maxLength
            if (maxLen < (i - um[sum]))
                maxLen = i - um[sum];
        }
    }
 
    // required maximum length
    return maxLen;
        
    }
};