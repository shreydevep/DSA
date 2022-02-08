class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        vector <int> freq(50001,0);
        int deg = 0;
        for(auto x : nums){
            freq[x]++;
            deg = max(deg,freq[x]);
        }
        map<int,pair<int,int>> occ;
        
        for(int i=0;i<50001;++i){
            if(freq[i] == deg){
                
                occ[i] = {-1,-1};
            }
        }
        
        for(int i=0;i<nums.size();++i){
            if(occ.find(nums[i]) != occ.end()){
                if(occ[nums[i]].first == -1){
                    occ[nums[i]] = {i,i};
                }
                else{
                    occ[nums[i]] = {occ[nums[i]].first,i};
                }
            }
        }
        int ans = nums.size();
        for(auto x : occ){
            
            auto y = x.second;
            //cout <<x.first <<" "<< y.first <<" "<< y.second <<"\n";
            ans = min(ans,(y.second- y.first + 1));
        }
        return ans;
    }
};