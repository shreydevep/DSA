class Solution {
public:
    string frequencySort(string s) {
        priority_queue<pair<int,char>> pq;
        unordered_map<char,int> freq;
        for(auto &x : s){
            freq[x]++;
        }
        
        for(auto &ch : freq){
            pq.push({ch.second,ch.first});
        }
        string res;
        while(!pq.empty()){
            res += string(pq.top().first,pq.top().second);
            pq.pop();
        }
        return res;
    }
};