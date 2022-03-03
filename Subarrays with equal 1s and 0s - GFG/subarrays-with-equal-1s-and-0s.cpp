// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
  public:
    //Function to count subarrays with 1s and 0s.
    long long int countSubarrWithEqualZeroAndOne(int arr[], int n)
    {
        //Your code here
        int diff[n+1] = {0};
        int zeros = 0;
        int ones = 0;
        for(int i=1;i<=n;++i){
            if(arr[i-1] == 0) zeros++;
            else ones++;
            diff[i] = (ones - zeros);
        }
        map<int,int> mp;
        
        int ans = 0;
        for(int i=1;i<=n;++i){
            if(mp.find(diff[i]) != mp.end()){
                ans += (mp[diff[i]]);
                //cout <<i <<" "<< diff[i] <<" "<<mp[-1*diff[i]] <<"*\n";
            }
            if(diff[i] == 0){
                ans++;
            }
            mp[diff[i]]++;
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
	int n,i;
	cin>>n;
	int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution obj;
	cout<< obj.countSubarrWithEqualZeroAndOne(arr, n)<<"\n";
	}
	return 0;
}
  // } Driver Code Ends