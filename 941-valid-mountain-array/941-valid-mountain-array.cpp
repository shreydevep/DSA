class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size() < 3) return false;
        
        int mx = INT_MIN;
        int pos = 0;
        for(int i=1;i<arr.size()-1;++i){
            if(mx < arr[i]){
                pos = i;
                mx = arr[i];
            }
        }
        
        for(int i=0;i<arr.size();++i){
            if(i < pos){
                if(arr[i] >= mx || arr[i] >= arr[i+1]) return false;
            }   
            else if(i == pos){
                continue;
            }
            else{
                if(arr[i] >= mx || arr[i-1] <= arr[i]) return false;
            }
        }
        return true;
        
    }
};