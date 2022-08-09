class Solution {
public:
    const int mod = 1e9 + 7;
    unordered_map<int,int> dp;
    unordered_set<int> st;
    long long recurr(int node){
        long long temp = 1;
        
        if(dp.find(node) != dp.end()) return dp[node];
        
        for(int i=2;i*i<=node;++i){
            if(node % i != 0) continue;
            
            int j = node/i;
            
            if(st.find(i) != st.end() && st.find(j) != st.end()){
                if(i == j){
                    temp = (temp % mod + (recurr(i) % mod * recurr(j) % mod)%mod )% mod;
                }
                else{
                    temp = (temp % mod + (2ll % mod * recurr(i) % mod * recurr(j) % mod)%mod )% mod;
                }
            }
        }
        return dp[node] = temp%mod;
    }
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(),arr.end());
       
        for(auto &x : arr){
           
            st.insert(x);
        }
        
        int ans = 0;
        for(int i=0;i<arr.size();++i){
            
            ans = (ans % mod + recurr(arr[i]) % mod) % mod;
        }
        return ans % mod;
    }
};