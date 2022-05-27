class Solution {
public:
    static bool comp(vector<int> &p1,vector<int> &p2){
        
         
         if(p1[1] == p2[1])  return p1[0] < p2[0];
         else return p1[1] < p2[1];
        
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        deque<pair<int,int>> q;
        vector<vector<int>> ans;
        sort(people.begin(),people.end(),comp);
        for(int i=0;i<people.size();++i){
            stack<pair<int,int>> temp;
            int cnt = 0;
            while(!q.empty()){
                
                if(q.front().first >= people[i][0]){
                    cnt++;
                }
                if(cnt > people[i][1]){
                    break;
                }
                temp.push(q.front());
               // cout << q.front()[0] <<" "<< q.front()[1] <<" ";
                q.pop_front();
                
            }
            //cout << people[i][0] <<" "<< cnt <<"\n";
            q.push_front({people[i][0],people[i][1]});
            while(!temp.empty()){
                q.push_front(temp.top());
                temp.pop();
            }
        }
        while(!q.empty()){
            ans.push_back({q.front().first,q.front().second});
            q.pop_front();
        }
        return ans;
    }
};