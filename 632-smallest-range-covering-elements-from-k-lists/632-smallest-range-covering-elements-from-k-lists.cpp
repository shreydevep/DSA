#define PII pair<int,int>
vector<vector<int>> temp;
class Solution {
public:
    class Compare{
       public:
        bool operator()(const PII &a,const PII &b){
            return temp[a.first][a.second] > temp[b.first][b.second];
        }
    };
    vector<int> smallestRange(vector<vector<int>>& nums) {
        temp = nums;
        priority_queue<PII,vector<PII>,Compare> pq;
        multiset<int> st;
        vector<int> ans(2);
        
        for(int i=0;i<nums.size();++i){
            pq.push({i,0});
            st.insert(nums[i][0]);
           
        }
        ans[0] = *st.begin();
        ans[1] = *st.rbegin();
        
        while(pq.size() == nums.size()){
            auto ptr = pq.top();
            pq.pop();
            st.erase(st.find(nums[ptr.first][ptr.second]));
            ptr = {ptr.first,ptr.second+1};
            if(ptr.second < nums[ptr.first].size()){
                st.insert(nums[ptr.first][ptr.second]);
                auto val = (*st.rbegin() - *st.begin());
                
                if(ans[1]-ans[0] > val){
                    ans[0] = *st.begin();
                    ans[1] = *st.rbegin();
                }
                pq.push(ptr);
            }
            
        }
        
        return ans;
        
        
    }
};

    