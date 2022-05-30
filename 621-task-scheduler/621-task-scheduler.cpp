class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
       
        
        unordered_map<char,int> freq;
        int cnt = tasks.size();
        for(auto &task : tasks){
            freq[task]++;
        }
        priority_queue<pair<int,char>> pq;
        unordered_map<int,pair<int,char>> reschedule;
        for(auto &x : freq){
            pq.push({x.second,x.first});
        }
        int timer = 0;
        
        while(cnt > 0 && timer < 1e5){
            if(reschedule.find(timer) != reschedule.end()){
               
                pq.push(reschedule[timer]);
            }
            if(pq.empty() && reschedule.find(timer) == reschedule.end()){
                
                timer++;
                continue;
            }
            
            auto val = pq.top();
            pq.pop();
            cnt--;
            timer++;
            
            val = {val.first-1,val.second};
            
            if(val.first > 0){
                reschedule[timer+n] = val;
            }
        }
        return timer;
        
        
    }
};