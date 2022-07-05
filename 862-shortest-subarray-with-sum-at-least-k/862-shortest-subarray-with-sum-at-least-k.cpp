class Solution {
public:
    
    int shortestSubarray(vector<int>& nums, int k) {
        vector<long> prefix(nums.size()+1,0);
        
        for(int i=0;i<nums.size();++i){
            prefix[i+1] = prefix[i] + (long)nums[i];
        }
        int ans = nums.size() + 1;
        deque<long> q;
        for(int i=0;i<prefix.size();++i){
            while(!q.empty() && prefix[i] <= prefix[q.back()]){
                q.pop_back();
            }
            while(!q.empty() && prefix[i] >= prefix[q.front()] + k){
                ans = min(ans,i - (int)q.front());
                q.pop_front();
            }
            q.push_back(i);
        }
        return ans < nums.size()+1 ? ans : -1;
        
    }
};
