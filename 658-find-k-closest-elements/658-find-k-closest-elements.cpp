class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        //So we need to get the window of size k such that the abs difference 
        //of elements is equal to k
        int L = 0;
        int R = arr.size() - 1;
        while(R-L >= k){
            if(L >= 0 && R < arr.size() && abs(arr[L] - x) < abs(arr[R] - x)){
                R--;
            }
            else if((abs(arr[L] - x) == abs(arr[R] - x) && arr[L] < arr[R])){
                R--;
            }
            else{
                L++;
            }
        }
        return vector<int> (begin(arr) + L, begin(arr) + R + 1);
    }
};