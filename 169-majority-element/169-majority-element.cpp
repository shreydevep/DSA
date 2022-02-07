class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele = 0;
        int cnt = 0;
        
        for(int i=0;i < nums.size();++i){
            if(cnt == 0) {
                ele = nums[i];
                cnt++;
            }
            else{
                if(ele == nums[i]) cnt++;
                else cnt--;
            }
        }
        return ele;
    }
};