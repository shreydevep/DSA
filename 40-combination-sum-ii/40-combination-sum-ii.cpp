class Solution {
public:
    vector<vector<int>> results;
    void recurr(int i,int target,vector<int> &candidates,vector<int> posCad){
        
        if(target == 0) {
                reverse(posCad.begin(),posCad.end());
                results.push_back(posCad);
                reverse(posCad.begin(),posCad.end());
                return;
        }
        if(target < 0 || i >= candidates.size()) return;
            
        for(int j=i;j<candidates.size();++j){
            if(j > i && candidates[j] == candidates[j-1]){
                continue;
            }
            int pick = candidates[j];
            
            posCad.push_back(pick);
            recurr(j+1,target - pick,candidates,posCad);
            posCad.pop_back();
            
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> posCad;
        recurr(0,target,candidates,posCad);
        return results;
    }
};

/**
Unlike Conmbination Sum I here we are not provided with unlimited choice
So we are given an array of values and a target sum, we need to find unique subsets of the array which is equal to the target.

So approach starts as follows:
1->We choose ith number or we don't
2-
3->Then at the end we array size becomes zero we insert the set into the ans array
**/