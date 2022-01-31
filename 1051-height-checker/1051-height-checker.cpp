class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector <int> freq(101,0);
        int h=0;
        int i=0;
        int ans = 0;
        for(auto x : heights){
            freq[x]++;
        }
        while(h < 101 && i < heights.size()){
            if(freq[h] == 0) {
                h++;
                continue;
            }
            
            if(h != heights[i]) {
                ans++;
            }
            
            freq[h]--;
            i++;
            
        }
        return ans;
    }
};