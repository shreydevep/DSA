#define pii pair<int,int>
#define ll long long
const ll mod = 1e9 + 7;
class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>> v;
        priority_queue<pii> pq;
        multiset<int> st;
        for(int i=0;i<n;++i){
            v.push_back({efficiency[i],speed[i]});
        }
        
        
        sort(v.begin(),v.end());
        for(int i=0;i<n;++i){
            pq.push({v[i].second,i});
        }
        long long sum = 0;
        
        for(int i=0;i<k;++i){
            
            sum = ((ll)sum+ (ll)pq.top().first);
            st.insert(pq.top().first);
            pq.pop();
        }
        long long ans = 0;
        for(int i=0;i<n;++i){
            
            ans = max(ans,((ll)v[i].first * (ll)sum));
            
            if(st.find(v[i].second) != st.end()){
                st.erase(st.find(v[i].second));
                sum = (sum - v[i].second );
            }
            while(st.size() < k && pq.size() > 0){
                if(pq.top().second < i){
                    pq.pop();
                    continue;
                }
                st.insert(pq.top().first);
                sum = (sum + pq.top().first);
                pq.pop();
            }
        }
        return ans % mod;
        
    }
};