class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
       int result = 0;
        unordered_set<int> hash;
        int i = 0;
        int j = 0;
        int score = 0;
        for (int j=0; j < nums.size(); j++) {
            while (hash.find(nums[j]) != hash.end()) {
                hash.erase(nums[i]);
                score -= nums[i];
                i++;
            }
            hash.insert(nums[j]);
            score += nums[j];
            result = max(result, score);
        }
        return result;
       
    }
};