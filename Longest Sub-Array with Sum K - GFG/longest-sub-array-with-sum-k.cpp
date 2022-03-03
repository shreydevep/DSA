// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int k) 
    { 
        // Complete the function
        map<int,vector<int>> freq;
        
        int prefix[N+1];
        prefix[0] = 0;
        
        for(int i=1;i<=N;++i){
            prefix[i] = prefix[i-1] + A[i-1]; 
        }
        int ans = 0;
        for(int i=1;i<=N;++i){
            int req = prefix[i] - k;
            
            if(freq.find(req) != freq.end()){
                for(auto pos : freq[req]){
                    ans = max(ans,abs(i-pos));
                }
            }
            if(req == 0){
                ans = max(ans,i);
            }
            
            freq[prefix[i]].push_back(i);
            
        }
        return ans;
    } 

};

// { Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends