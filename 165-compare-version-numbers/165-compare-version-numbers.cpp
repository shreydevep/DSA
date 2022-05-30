class Solution {
public:
    vector<int> getVer(string s){
        stringstream ss(s);
        string word;
        vector<int> res;
        while (ss.good()) 
        {
            getline(ss, word, '.');
            res.push_back(stoi(word));
        }
        return res;
    }
    
    int compareVersion(string version1, string version2) {
        vector<int> v1 = getVer(version1);
        vector<int> v2 = getVer(version2);
        while(v1.size() > 0 && v1.back() == 0){
            v1.pop_back();
        }
         while(v2.size() > 0 && v2.back() == 0){
            v2.pop_back();
        }
        
        for(int i=0;i<min(v1.size(),v2.size());++i){
            if(v1[i] < v2[i]) return -1;
            else if(v1[i] > v2[i]) return 1;
        }
        if(v1.size() > v2.size()) return 1;
        else if(v1.size() < v2.size()) return -1;
        return 0;
    }
};