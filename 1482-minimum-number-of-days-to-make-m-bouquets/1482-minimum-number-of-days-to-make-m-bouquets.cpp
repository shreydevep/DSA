class Solution {
public:
    bool check(vector<int>& bloomDay,int day,int k,int m){
        int cnt_k = 0;
        int temp_k = 0;
        for(int i=0;i<bloomDay.size();++i){
            if(temp_k > 0 && temp_k % k == 0){
                cnt_k++;
                temp_k = 0;
            }
            if(bloomDay[i] <= day){
                temp_k++;
            }
            else{
                temp_k = 0;
            }
        }
         if(temp_k > 0 && temp_k % k == 0){
                cnt_k++;
                temp_k = 0;
         }
        return (cnt_k >= m);
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(bloomDay.size() < ((long long)m*(long long)k)) return -1;
        
        int l = 1;
        int r = 1e9+1;
        int ans = 1e9 + 1;
        while(l < r){
            int mid_day = l + (r-l)/2;
            if(check(bloomDay,mid_day,k,m)){
                ans = mid_day;
                r = mid_day;
            }
            else{
                l = mid_day+1;
            }
        }
        return ans;
    }
};