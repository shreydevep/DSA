// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int sortingCost(int N, int arr[]){
        // code here
        
        map<int,int> mp;
        
        for(int i=0;i<N;++i){
            
            if(mp.find(arr[i]-1) != mp.end()){
                    mp[arr[i]] = mp[arr[i]-1] + 1; 
                    mp.erase(arr[i]-1);
            }
            else{
                mp[arr[i]] = 1;
            }
        }
        int len = 0;
        for(auto x : mp){
            len = max(len,x.second);
        }
        return (N-len);
    }
    
    // 5 6 7 1 2 3 4
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        Solution ob;
        
        cout<<ob.sortingCost(N, arr)<<"\n";
    }
    return 0;
}  // } Driver Code Ends