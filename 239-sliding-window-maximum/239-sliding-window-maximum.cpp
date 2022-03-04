class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque <int> q;
        int i=0;
        vector <int> ans;
        int curr = 0;
        for(i=0;i<k;++i){
            if(!q.empty() && q.back() < nums[i]){
                while(!q.empty()) q.pop_back();
                q.push_back(nums[i]);
            }
            else{
                while(!q.empty() && q.front() < nums[i]){
                    q.pop_front();
                }
                q.push_front(nums[i]);
            }
            
        }
        
        ans.push_back(q.back());
        for(int i=k;i<nums.size();++i){
            if(!q.empty() && q.back() == nums[curr]) q.pop_back();
            if(!q.empty() && q.back() < nums[i]){
                while(!q.empty()) {
                        q.pop_back();
                    }
                q.push_back(nums[i]);
            }
            else{
                while(!q.empty() && q.front() < nums[i]){
                    q.pop_front();
                }
                q.push_front(nums[i]);
            }
            ans.push_back(q.back());
            curr++;
        }
        return ans;
    }
};