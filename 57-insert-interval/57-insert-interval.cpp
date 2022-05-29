class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        for(int i=1;i<intervals.size();++i){
            if(intervals[i][0] <= res.back()[1]){
                auto val = res.back();
                res.pop_back();
                val[0] = min(intervals[i][0],val[0]);
                val[1] = max(intervals[i][1],val[1]);
                res.push_back(val);
            }
            else{
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};