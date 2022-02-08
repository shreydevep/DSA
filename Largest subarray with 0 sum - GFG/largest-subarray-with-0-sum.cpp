// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        int prefix[n+1] = {0};
        prefix[0] = A[0];
        int ans = 0;
        for(int i=1;i<n;++i){
            prefix[i] += (prefix[i-1] + A[i]);
        }
        map<int,set<int>> mp;
        for(int i=0;i<n;++i){
            mp[prefix[i]].insert(i);
        }
        int target = 0;
        for(int i=0;i<n;++i){
            if(i == 0){
                for(auto y : mp[target]){
                    if(y != i && y > i){
                        ans = max(ans,(y-i+1));
                    }
                }
            }
            else{
                target = prefix[i-1];
                for(auto y : mp[target]){
                    if(y != i && y > i){
                        ans = max(ans,(y-i+1));
                    }
                }
                
            }
        }
        return ans;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}


  // } Driver Code Ends