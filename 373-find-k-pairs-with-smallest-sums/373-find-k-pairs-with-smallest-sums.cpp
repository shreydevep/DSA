#include <bits/stdc++.h>
#define ll long long

class Solution {
    
public:
    
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        vector<pair<long long,pair<int,int>>> p;
        for(int i=0;i<min(k,(int)nums1.size());++i){
            if(i == 0){
                for(int j=0;j<min(k,(int)nums2.size());++j){
                p.push_back({nums1[i] + nums2[j],{nums1[i],nums2[j]}});
                }
                continue;
            }
                
            for(int j=0;j<min((k/i),(int)nums2.size());++j){
                p.push_back({nums1[i] + nums2[j],{nums1[i],nums2[j]}});
            }
        }
        sort(p.begin(),p.end());
        int cnt = 0;
        long long xx = ((long long)(nums1.size()))*((long long)(nums2.size()));
        for(int i=0;i<min((long long)k,xx);++i){
            vector<int> temp;
            temp.push_back(p[i].second.first);
            temp.push_back(p[i].second.second);
            ans.push_back(temp);
        }
        return ans;
        
    }
};