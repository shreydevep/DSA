// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	long long subCount(long long arr[], int N, long long K)
	{
	    // Your code goes here
	    int prefix[N+1] = {0};
	    
	    for(int i=1;i<=N;++i){
	        prefix[i] = (prefix[i-1]%K + arr[i-1]%K + K) %K;
	    }
	   
	    unordered_map<int,long long > mp;
	    long long ans = 0;
	    for(int i=1;i<=N;++i){
	        int req = prefix[i];
	        if(mp.find(req) != mp.end()){
	            ans += (mp[req]);
	        }
	        if(req == 0){
	            ans++;
	        }
	        mp[prefix[i]]++;
	    }
	    return ans;
	    
	    
	}



};


// { Driver Code Starts.

int main() 
{
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
       	long long k;
		cin>>n >> k;
		long long a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];
        

        Solution ob;
        cout << ob.subCount(a, n, k);
	    cout << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends