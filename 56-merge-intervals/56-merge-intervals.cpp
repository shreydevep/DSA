class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> merge_intervals;
        int last = 0;
        merge_intervals.push_back(intervals[0]);
        for(int i=1;i<intervals.size();++i){
            if(intervals[i][0] <= merge_intervals[last][1]){
                merge_intervals[last][1] = max(merge_intervals[last][1],intervals[i][1]);
            }
            else{
                merge_intervals.push_back(intervals[i]);
                last++;
            }
        }
        return merge_intervals;
    }
};