class Solution {
public:
    vector<int> countBits(int n) {
        //O(nlog n)
        vector <int> ans;
        for(int i=0;i<=n;++i){
            int cnt = 0;
            for(int j=31;j>=0;--j){
                if(i & (1 << j)){
                    cnt++;
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};