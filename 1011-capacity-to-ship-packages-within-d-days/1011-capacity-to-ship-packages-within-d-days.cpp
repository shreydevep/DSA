class Solution {
public:
    bool check(vector<int> &weights,int limit_weight,int req_days){
        int days_cnt = 0;
        int curr = 0;
        for(int i=0;i<weights.size();++i){
            if(weights[i] > limit_weight) return false;
            if(curr + weights[i] <= limit_weight){
                curr +=weights[i];
            }
            else{
                days_cnt++;
                curr = weights[i];
            }
        }
        if(curr > 0) days_cnt++;
        return (days_cnt <= req_days);
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int l = 1;
        int r = 1e7;
        int ans = r;
        while(l < r){
            int mid = l + (r-l)/2;
            if(check(weights,mid,days)){
                ans = mid;
                r = mid;
            }
            else{
                l = mid + 1;
            }
        }
        return ans;
    }
};