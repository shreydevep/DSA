// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
  public:
    int findPairs(int arr[], int n)
    {
       //code here.
       unordered_map<int,int> hash;
       for(int i=0;i<n;++i){
           for(int j=i+1;j<n;++j){
               hash[arr[i]*arr[j]]++;
               if(hash[arr[i]*arr[j]] > 1) return 1;
           }
       }
       
       return -1;
    }
    
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;    
       cout<<ob.findPairs(arr, n)<<endl;        
    }
  
    return 0;
}  // } Driver Code Ends