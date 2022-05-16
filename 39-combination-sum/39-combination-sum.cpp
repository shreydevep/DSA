class Solution {
public:
   vector<vector<int>> results;
    void recurr(int i,int target,vector<int> &candidates,vector<int> posCad){
        if(target == 0) {
                reverse(posCad.begin(),posCad.end());
                results.push_back(posCad);
                return;
        }
        if(target < 0 or i < 0) return;
        
        
        posCad.push_back(candidates[i]);
        recurr(i,target-candidates[i],candidates,posCad);
        posCad.pop_back();
        recurr(i-1,target,candidates,posCad);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> posCad;
        recurr(candidates.size()-1,target,candidates,posCad);
        return results;
    }
};
