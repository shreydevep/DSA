// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();++i){
            nums[i] = (nums[i] + k) % k;
        }
        for(auto x : nums){
            mp[x]++;
        }
        
        for(int i=0;i<nums.size();++i){
            if(mp.find(nums[i]) == mp.end()) continue;
            
            mp[nums[i]]--;
            if(mp[nums[i]] == 0) mp.erase(nums[i]);
            
            if(mp.find(k-nums[i]) == mp.end()){
                mp[nums[i]]++;
            }
            else{
                mp[k-nums[i]]--;
                if(mp[k - nums[i]] == 0) mp.erase(k-nums[i]);
                
            }
        }
        if(mp.find(0) != mp.end()){
            if(mp[0] % 2 == 0) mp.erase(0);
        }
        if(mp.size() > 0) return false;
        
        return true;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}  // } Driver Code Ends