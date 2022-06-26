class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        vector<int> prefix(cardPoints.size()+2,0);
        
        for(int i=1;i<=cardPoints.size();++i){
            prefix[i] = prefix[i-1] + cardPoints[i-1];
        }
        vector<int> suffix(cardPoints.size()+2,0);
        
        suffix[cardPoints.size()] = cardPoints.back();
        for(int i=cardPoints.size();i>=1;--i){
            suffix[i] = suffix[i+1] + cardPoints[i-1];
        }
        int ans = 0;
        for(int i=0;i<=k;++i){
            int j = cardPoints.size()-(k-i)+1;
            ans = max(ans,prefix[i]+suffix[j]);
        }
        return ans;
    }
};