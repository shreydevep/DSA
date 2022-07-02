class Solution {
public:
    int ans = 0;
    bool check(vector<int> &prem,int &n){
        for(int i=0;i<prem.size();++i){
            if((prem[i] % (i+1) != 0) && (((i+1) % prem[i]) != 0)){
                return false;
            }
        }
        return true;
    }
    bool check_small(int val,int pos){
        if(val % pos != 0 && pos % val != 0) return false;
        return true;
    }
    void recurr(int vis_mask,vector<int> &prem,int &n){
        if(vis_mask == ((1<< n)-1)){
            if(check(prem,n)){
                ans++;
            }
            return;
        }
        for(int k=0;k<n;++k){
            if((vis_mask & (1 << k)) == 0 && check_small(k+1,prem.size()+1)){
                prem.push_back(k+1);
                recurr((vis_mask | (1 << k)),prem,n);
                prem.pop_back();
            }
        }
    }
    int countArrangement(int n) {
        vector<int> prem;
        recurr(0,prem,n);
        return ans;
    }
};