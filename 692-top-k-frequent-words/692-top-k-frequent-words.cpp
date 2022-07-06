#define PIS pair<int,string>  
class Solution {
public:
    struct Compare {
        bool operator()(PIS const& p1, PIS const& p2)
        {
            if(p1.first == p2.first){
                return (p1.second < p2.second);
            }
            else{
                return (p1.first > p2.first);
            }
        }
    };
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> hash;
       
        priority_queue<PIS,vector<PIS>,Compare> pq;
        vector<string> res;
        for(auto &x : words) hash[x]++;
        
        for(auto &word : hash){
            pq.push({word.second,word.first});
            if(pq.size() > k) pq.pop();
        }
        while(!pq.empty()){
            res.push_back((pq.top().second));
            pq.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};