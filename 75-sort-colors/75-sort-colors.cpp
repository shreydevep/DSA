class Solution {
public:
    void sortColors(vector<int>& arr) {
        int n = arr.size();
         int pos_0 = 0;
    int pos_2 = n-1;
    for(int i=0;i<n;++i){
        while(pos_0 < n && arr[pos_0] == 0) pos_0++;        
        if(arr[i] == 0 && i > pos_0 && pos_0 < n){
            swap(arr[i],arr[pos_0]);
            pos_0++;
        }
    }
    for(int i=pos_0;i<n;++i){
        while(pos_2 >=0 && arr[pos_2] == 2) pos_2--;
        if(arr[i] == 2 && i < pos_2 && pos_2 >= 0){
            swap(arr[i],arr[pos_2]);
            pos_2--;
        }
    }
    }
};