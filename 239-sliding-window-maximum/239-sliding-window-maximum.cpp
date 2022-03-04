class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> st;
        priority_queue<int> pq;
        vector<int> ans;
        int i=0;
        
        for(i=0;i<k;++i){
            st.insert(nums[i]);
            pq.push(nums[i]);
        }
        ans.push_back(pq.top());
        int curr = 0;
        for(int i=k;i<nums.size();++i){
            st.erase(st.find(nums[curr]));
            st.insert(nums[i]);
            pq.push(nums[i]);
            
            while(!pq.empty() && st.find(pq.top()) == st.end()){
                pq.pop();
            }
            ans.push_back(pq.top());
            curr++;
        }
        return ans;
    }
};