class Solution {
public:
    int getNextJob(vector<vector<int>>& jobs, int idx)
    {
        int n = jobs.size();
	    int lo = idx+1, hi = n-1, ans = jobs.size();
	    while(lo <= hi) {
		    int mid = (lo + hi) >> 1;
		    if(jobs[idx][1] <= jobs[mid][0])
		    {
			    ans = mid;
			    hi = mid-1;
		    }
		    else lo = mid + 1;
	    }
	    return ans;
    }
    
    unordered_map<int,int> dp;
    int recurr(int idx,vector<vector<int>> &startTime){
        if(idx == startTime.size()) return 0;
        if(dp.find(idx) != dp.end()) return dp[idx];
        int temp = getNextJob(startTime,idx);
        
        return dp[idx] = max(startTime[idx][2] + recurr(temp,startTime),recurr(idx+1,startTime));
        
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> v;
        
        for(int i=0;i<startTime.size();++i){
            v.push_back({startTime[i],endTime[i],profit[i]});
        }
        sort(v.begin(),v.end());
       
        
        return recurr(0,v);
        
    }
};
