class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size() < 3) return false;
        
        int pos = 0;
        while(pos+1 < arr.size() && arr[pos] <arr[pos+1]){
            pos++;
        }
        if(pos == 0 || pos == arr.size()-1) return false;
        
        while(pos+1 < arr.size() && arr[pos] > arr[pos+1]){
            pos++;
        }
        return (pos == arr.size()-1);
        
    }
};