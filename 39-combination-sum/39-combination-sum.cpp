class Solution {
public:
   vector<vector<int>> results;
    void recurr(int i,int target,vector<int> &candidates,vector<int> &posCad){
        if(target == 0) {
                reverse(posCad.begin(),posCad.end());
                results.push_back(posCad);
                reverse(posCad.begin(),posCad.end());
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
/**
Here the approach goes as follows:
1-> Unique numbers so either we choose a number or we don't until we have now choice just to leave the number;
2-> No sorting is required as for every number we are exporing the 2 states;

**/