class Solution {
public:
    int totalFruit(vector<int>& fruits) {
       unordered_map<int,int> mp;
        int i=0;
        int j=0;
        int ans = 0;
        while(j < fruits.size()){
            while(mp.size() <= 2 && j < fruits.size()){
                mp[fruits[j]]++;
                if(mp.size() <= 2){
                    ans = max(ans,j-i + 1);
                }
                j++;
            }
            while(mp.size() > 2 && i <= j){
                mp[fruits[i]]--;
               
                if(mp[fruits[i]] == 0){
                    mp.erase(mp.find(fruits[i]));
                }
                i++;
            }
        }
        
        return ans;
    }
};