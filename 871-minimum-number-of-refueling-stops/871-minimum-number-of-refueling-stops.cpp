class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        if(stations.size() == 0 and startFuel < target) return -1;
        priority_queue<pair<int,int>> pq;
        int fuel = startFuel;
        int prev = 0;
        int ans = 0;
        if(stations.size() > 0 and stations.back()[0] != target){
           vector<int> temp = {target,0};
            stations.push_back(temp);
        }
        
        
        
        for(auto &d : stations){
            int dist = d[0] - prev;
            
            if(dist > fuel){
                while(!pq.empty() and fuel < dist){
                    auto temp = pq.top();
                    ans++;
                    fuel += temp.first;
                    pq.pop();
                }
                
                
                if(pq.empty() and fuel < dist) {
                    ans = -1;
                    break;
                }
            }
            fuel -= dist;
            prev = d[0];
            pq.push({d[1],d[0]});
        }
        
        
        return ans;
    }
};

