class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        long long diff = 100000;
        int ans = 0;
        for(int i=0;i<nums.size();++i){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int j=i+1;
            int k=nums.size()-1;
            while(j < k){
               long long sum = nums[i] + nums[j] + nums[k];
                //cout << target <<" "<< sum <<"\n";
                long long d = abs(target-sum);
                if(d < diff){
                    diff = d;
                    ans = sum;
                }
                if(sum <= target) j++;
                else k--;
                    
                
            }
        }
        return (int)ans;
    }
};