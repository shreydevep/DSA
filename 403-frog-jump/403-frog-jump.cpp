class Solution {
public:
    vector<vector<int>> dp;
    bool recurr(int i,int j,vector<int>& stones){
        
        if(i == stones.size()-1) return true;
        if(i >= stones.size()) return false;
        int lastJump = stones[i]-stones[j];
        if(dp[i][j] != -1) return dp[i][j];
        auto jump = lower_bound(stones.begin()+i+1,stones.end(),lastJump+stones[i]);
        
        auto jump_plus = lower_bound(stones.begin()+i+1,stones.end(),lastJump+1 + stones[i]);
        auto jump_min =  lower_bound(stones.begin()+i+1,stones.end(),lastJump-1 + stones[i]);
        
        bool ans1 = false,ans2 = false,ans3 = false;
        if(jump < stones.end() && (*jump - stones[i]) == lastJump){
            ans3 = recurr(jump-stones.begin(),i,stones);
        }
        if(jump_plus < stones.end() && (*jump_plus -stones[i]) == lastJump + 1){
            ans1 = recurr(jump_plus-stones.begin(),i,stones);
        }
                         
        if(jump_min < stones.end() && (*jump_min - stones[i]) == lastJump - 1){
             ans2 = recurr(jump_min-stones.begin(),i,stones);
        }
        return dp[i][j] = (ans1|ans2|ans3);
    }
    bool canCross(vector<int>& stones) {
        dp.resize(stones.size(),vector<int>(stones.size(),-1));
        return recurr(0,0,stones);
    }
};