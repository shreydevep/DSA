class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<mat.size();++i){
            int sum = 0;
            for(int j=0;j<mat[0].size();++j){
                sum += mat[i][j];
            }
            pq.push({sum,i});
            if(pq.size() > k){
                pq.pop();
            }
        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back((pq.top()).second);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};