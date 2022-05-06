class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int first = 0;
        int second = 0;
        vector<vector<int>> results;
        while(first < firstList.size() && second < secondList.size()){
            auto f = firstList[first];
            auto s = secondList[second];
            if(f[1] < s[0]){
                first++;
                continue;
            }
            
            if(s[1] < f[0]){
                second++;
                continue;
            }
            vector<int> result;
            result.push_back(max(f[0],s[0]));
            result.push_back(min(f[1],s[1]));
            results.emplace_back(result);
            if(f[1] == s[1]){
                first++;
                second++;
            }
            else if(f[1] < s[1]){
                first++;
            }
            else{
                second++;
            }
            
            
        }
        return results;
    }
};