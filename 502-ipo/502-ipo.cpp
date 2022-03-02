class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        
        priority_queue<int> hash;
        vector<pair<int,int>> cp;
        for(int i=0;i<capital.size();++i){
            cp.push_back({capital[i],profits[i]});
        }
        sort(cp.begin(),cp.end());
        int pos = 0;
        while(pos < cp.size() && cp[pos].first <= w){
            hash.push(cp[pos].second);
            pos++;
        }
        int curr = 1;
        while(hash.size() > 0 && curr <= k){
            
            w += hash.top();
            hash.pop();
            curr++;
            while(pos < cp.size() && cp[pos].first <= w){
                hash.push(cp[pos].second);
                pos++;
            }
        }
        return w;
    }
};