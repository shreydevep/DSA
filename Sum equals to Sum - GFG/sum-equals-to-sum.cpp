// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
  public:
    int findPairs(long long a[], long long n)
    {
        //code here.
        
        unordered_map<long long,long long> mp;
        
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j){
                mp[a[i] + a[j]]++;
                if(mp[a[i] + a[j]] > 1) return 1;
            }
        }
        
        return 0;
        
        
    }
};

// { Driver Code Starts.
int main() {
	long long t;
	
	cin >> t;
	
	while(t--){
	    long long n;
	    cin >> n;
	    long long a[n];
	    for(long long i = 0;i<n;i++){
	        cin >> a[i];
	        // um[a[i]]++;
	    }
	    Solution ob;
	    cout << ob.findPairs(a, n) << endl;   
	    }
	return 0;
}
  // } Driver Code Ends