class Solution {
public:
   
    unordered_map<int,int> hash;
    int lenLongestFibSubseq(vector<int>& arr) {
        int ans = 0;
        
        for(int i=0;i<arr.size();++i){
           hash[arr[i]] = i;
        }
        
        for(int i=0;i<arr.size();++i){
            for(int j=i+1;j<arr.size();++j){
                int key = arr[i] + arr[j];
                int cnt = 2;
                int prev = arr[i];
                while(hash.find(key) != hash.end()){
                    int temp = key;
                    key = key - prev + arr[hash[key]];
                    prev = temp - prev;
                    
                    cnt++;
                }
                ans = max(ans,cnt);
            }
        }
        if(ans == 2) ans = 0;
        return ans;
    }
};