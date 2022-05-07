class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        //So we need to get the window of size k such that the abs difference 
        //of elements is equal to k
        
        int R = lower_bound(arr.begin(),arr.end(),x) - arr.begin();
        int L = R-1;
        while(k--){
            if(R >= arr.size() || (L>=0 && abs(arr[L] - x) < abs(arr[R] - x))){
                L--;
            }
            else if(L>= 0 && abs(arr[L] - x) == abs(arr[R] - x) && arr[L] < arr[R]){
                L--;
            }
            else{
                R++;
            }
        }
        
        return vector<int> (begin(arr) + L + 1, begin(arr) + R);
    }
};