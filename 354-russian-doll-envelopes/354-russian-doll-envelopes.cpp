class Solution {
 
public:
    static bool sortCompare(vector<int> const &p1,vector<int> const &p2){
        if(p1[0] == p2[0]){
            return (p1[1] > p2[1]);
        }
        return (p1[0] < p2[0]);
    }
    int lis(vector<int> v){
        vector<int> temp;
        int len = 0;
        for(int i=0;i<v.size();++i){
            auto itr = lower_bound(temp.begin(),temp.end(),v[i]);
            if(itr == temp.end()){
                len++;
                temp.push_back(v[i]);
            }
            else{
                *itr = v[i];
            }
        }
        return len;
        
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),sortCompare);
        vector<int> width;
        width.push_back(envelopes[0][1]);
        int last = envelopes[0][0];
        for(int i=1;i<envelopes.size();++i){
            width.push_back(envelopes[i][1]);
            last = envelopes[i][0];
        }
        
        return lis(width);
    }
};

/**
6  -1 4 7
5 -1 4
2 3

**/