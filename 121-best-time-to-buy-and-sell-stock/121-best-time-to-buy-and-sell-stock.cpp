class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int curr = prices[0];
        int ans = 0;
        for(int i=1;i<prices.size();++i){
            ans = max(ans,prices[i]-curr);
            curr = min(prices[i],curr);
        }
        return ans;
    }
};