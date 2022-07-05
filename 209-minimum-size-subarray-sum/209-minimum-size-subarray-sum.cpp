class Solution {
public:
    
    int minSubArrayLen(int k, vector<int>& nums) {
        int i=0;
        deque<int> q;
        int ans = INT_MAX;
        int sum = 0;
        while(i < nums.size() && nums[i] < 0) i++;
        while(i < nums.size()){
            
            if(sum + nums[i] >= k){
                ans = min(ans, (int)q.size()+1);
                while(q.size() > 0 && sum >= k){
                        sum -= q.front();
                        ans = min(ans, (int)q.size());
                        q.pop_front();
                }
            }
            sum += nums[i];
            q.push_back(nums[i]);
            i++;
        }
        while(!q.empty()){
            if(sum >= k){
                ans = min(ans,(int)q.size());
            }
            sum -= q.front();
            q.pop_front();
        }
        if(sum >= k){
            ans = min(ans,(int)q.size());
        }
        if(ans == INT_MAX) ans = 0;
        return ans;
    }
};