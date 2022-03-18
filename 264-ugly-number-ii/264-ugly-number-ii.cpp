class Solution {
public:
   
    
    int nthUglyNumber(int n) {
        priority_queue<int,vector<int>,greater<int>> pq;
        
        pq.push(2);
        pq.push(3);
        pq.push(5);
        vector <int> dp;
        set<int> st;
        dp.push_back(1);
        while(pq.size() < n+1){
            auto val = pq.top();
            dp.push_back(val);
            pq.pop();
            
            if(val <= (INT_MAX/2) && st.find(val*2) == st.end()){
                pq.push(val*2);
                st.insert(val*2);
            }
            if(val <= (INT_MAX/3) && st.find(val*3) == st.end()){
                pq.push(val*3);
                st.insert(val*3);
            }
            if(val <= (INT_MAX/5) && st.find(val*5) == st.end()){
                pq.push(val*5);
                st.insert(val*5);
            }
        }
        int cnt = dp.size();
        while(!pq.empty() && cnt < n+1){
            auto val = pq.top();
            dp.push_back(val);
            pq.pop();
            cnt++;
        }
        //cout << cnt <<"\n";
        return dp[n-1];
    }
};