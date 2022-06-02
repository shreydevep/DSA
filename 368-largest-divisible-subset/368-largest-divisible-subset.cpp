class Solution {
public:
   
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        vector<int> t(nums.size()+1,1);
        vector<int> hash(nums.size()+1,0);
        for(int i=0;i<nums.size();++i) hash[i] = i;
        
        for(int i=0;i<nums.size();++i){
            for(int j=0;j<i;++j){
                if(nums[i] % nums[j] == 0){
                    if(1 + t[j] > t[i]){
                        hash[i] = j;
                        t[i] = 1 + t[j];
                    }
                }
            }
        }
        
        int mx_ind = 0;
        for(int i=0;i<nums.size();++i){
            if(t[mx_ind] < t[i]){
                mx_ind = i;
            }
        }
        vector<int> ans;
        while(hash[mx_ind] != mx_ind){
            ans.push_back(nums[mx_ind]);
            mx_ind = hash[mx_ind];
        }
        ans.push_back(nums[mx_ind]);
        
        return ans;
    }
};