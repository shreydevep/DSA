class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
       
        int curr_fuel = startFuel;
        
        priority_queue<int> pq;
        int curr_pos = 0;
        int ans = 0;
        for(int i=0;i<stations.size();++i){
            curr_fuel -= (stations[i][0]-curr_pos);
            curr_pos = stations[i][0];
            
            while(!pq.empty() && curr_fuel < 0){
                curr_fuel += pq.top();
                
                pq.pop();
                ans++;
            }
            
            if(curr_fuel < 0) return -1;
            pq.push(stations[i][1]);
            
            
        }
        
        curr_fuel -= (target - curr_pos);
        while(!pq.empty() && curr_fuel < 0){
                curr_fuel += pq.top();
                
                pq.pop();
                ans++;
        }
        if(curr_fuel < 0) return -1;
        
        return ans;
        
    }
};