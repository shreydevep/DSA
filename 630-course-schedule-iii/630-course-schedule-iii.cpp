class Solution {
public:
    static bool compare(vector<int> &a,vector<int> &b){
        return a[1] < b[1];
    }
    
    int scheduleCourse(vector<vector<int>>& courses) {
        
        sort(courses.begin(),courses.end(),compare);
        
        priority_queue<int> pq;
        int time = 0;
        for(auto &x : courses){
            pq.push(x[0]);
            time += x[0];
            if(time > x[1]){
                time -= pq.top();
                pq.pop();
            }
        }
        return (int)pq.size();
        
    }
};