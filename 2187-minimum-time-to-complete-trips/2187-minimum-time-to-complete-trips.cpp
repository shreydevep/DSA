class Solution {
public:
    bool getTrips(vector<int> &time,long long currTime,long long totalTrips){
        long long trips = 0;
        for(auto &x : time){
            if(trips >= totalTrips) return true;
            trips += ((currTime/x));
        }
        if(trips >= totalTrips) return true;
        
        return false;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        
        sort(time.begin(),time.end());
        long long startTime = 0;
        long long endTime = 1e15;
        long long ans = 1e15;
        while(startTime <= endTime){
            long long mid = startTime + (endTime-startTime)/2;
           bool currTrips = getTrips(time,mid,totalTrips);
            
            if(currTrips){
                ans = min(ans,mid);
                endTime = mid-1;
            }
            else{
                startTime = mid+1;
            }
        }
        return ans;
        
        
    }
};