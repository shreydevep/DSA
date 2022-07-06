#define PII pair<int,int>
class Solution {
public:
    struct Compare{
        bool operator()(PII const &p1,PII const &p2){
            return (p1.second > p2.second);
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
      priority_queue<PII,vector<PII>,Compare> pq;
        unordered_map<int,int> mp;
        for(auto &num : nums){
            
            mp[num]++;
            
        }
        for(auto &x : mp){
            pq.push({x.first,x.second});
            if(pq.size() > k) pq.pop();
        }
        vector<int> res;
        while(!pq.empty()){
            res.push_back(pq.top().first);
            pq.pop();
        }
        return res;
    }
};