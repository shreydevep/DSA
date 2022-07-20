class Solution {
public:
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        vector<int> ptrs(matrix.size(),0);
        for(int i=0;i<ptrs.size();++i){
                pq.push({matrix[i][ptrs[i]],{i,ptrs[i]}});
        }
        while(k > 1){
            
            auto val = pq.top();
            pq.pop();
            k--;
            int new_ptr = val.second.second + 1;
            if(new_ptr < matrix[0].size()){
                pq.push({matrix[val.second.first][new_ptr],{val.second.first,new_ptr}});
            }
        }
        return pq.top().first;
    }
};
