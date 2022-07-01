class Solution {
public:
    bool check(vector<int>& bloomDay,int mid,int k,int m){
        int n = bloomDay.size();
        int tot = 0;
        for(int i=0;i<n;){
            while(i < n && bloomDay[i]>mid)i++;
            int j=i;
            int cnt=0;
            while(j<n&&cnt<k&&bloomDay[j]<=mid){
                j++;
                cnt++;
            }
            if(cnt==k)tot++;
            i=j;
        }
        return (tot >= m);
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