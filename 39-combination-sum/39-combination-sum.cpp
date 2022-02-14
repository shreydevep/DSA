class Solution {
public:
    vector<vector<int>> ans;
    void recurr(int index,vector<int> &res,vector <int> &candidates,int target){
         if(target == 0){
            ans.push_back(res);
             return;
        }
        if(target < 0 || index == candidates.size()){
            return;
        }
        for(int cnt=0;cnt<=(target/candidates[index]);++cnt){
            for(int k=1;k<=cnt;++k){
                res.push_back(candidates[index]);
            }
            recurr(index+1,res,candidates,target-(cnt*candidates[index]));
             for(int k=1;k<=cnt;++k){
                res.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> res;   
        recurr(0,res,candidates,target);
        return ans;
    }
};