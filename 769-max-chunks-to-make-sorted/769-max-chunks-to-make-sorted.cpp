class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int curr = -1;
        int ans = 0;
        for(int i=0;i<arr.size();++i){
            curr = max(curr,arr[i]);
            if(curr == i){
                ans++;
                curr = i+1;
            }
        }
        return ans;
    }
};