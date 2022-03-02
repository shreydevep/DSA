// { Driver Code Starts
// Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int isPossible(int N, int arr[], int K){
        unordered_map<int,int> mp;
        int mx = 0;
        for(int i=0;i<N;++i){
            mp[arr[i]]++;
        }
        for(auto x : mp){
            mx = max(mx,x.second);
        }
        mx = (mx + 1)/2;
        if(mx > K) return 0;
        return 1;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, K;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        cin>>K;
        
        Solution ob;
        cout<<ob.isPossible(N, arr, K)<<"\n";
    }
    return 0;
}  // } Driver Code Ends