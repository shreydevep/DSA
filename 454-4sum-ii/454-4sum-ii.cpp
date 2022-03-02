class Solution {
public:
    unordered_map<int,int> getPairSum(vector <int> &num1,vector <int> &num2){
        unordered_map<int,int> mp;
        
        for(int i=0;i<num1.size();++i){
            for(int j=0;j<num2.size();++j){
                mp[num1[i]+num2[j]]++;
            }
        }
        return mp;
    }
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int> pair_sum_mp1 = getPairSum(nums1,nums2);
        unordered_map<int,int> pair_sum_mp2 = getPairSum(nums3,nums4);
        int ans = 0;
        for(auto sum1 : pair_sum_mp1){
            if(pair_sum_mp2.find(-1*sum1.first) != pair_sum_mp2.end()){
                ans += (sum1.second * pair_sum_mp2[-1*sum1.first]);
            }
        }
        return ans;
    }
};