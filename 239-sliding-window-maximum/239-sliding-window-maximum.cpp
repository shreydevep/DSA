class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        int j = 0;
        for(int i=0;i<min(k,(int)nums.size());++i){
            
            while(!q.empty() && nums[q.back()] < nums[i]) q.pop_back();
            
            q.push_back(i);
            j++;
        }
        vector<int> res;
        res.push_back(nums[q.front()]);
        while(j < nums.size()){
             while(!q.empty()  && nums[q.back()] < nums[j]){ 
                 q.pop_back();
             }
             while(!q.empty() && q.front() < (j-k + 1) ) q.pop_front();
             
             q.push_back(j);
             res.push_back(nums[q.front()]);
             j++;
        }
        
        return res;
    }
};



