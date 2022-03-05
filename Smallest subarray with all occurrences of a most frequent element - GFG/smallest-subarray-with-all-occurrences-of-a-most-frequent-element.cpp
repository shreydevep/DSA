// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    vector<int> smallestSubsegment(int a[], int n)
    {
    	// Complete the function
    	unordered_map<int,pair<int,int>> mp;
        for(int i=0;i<n;++i){
            if(mp.find(a[i]) == mp.end()){
                mp[a[i]] = {1,i};
            }
            else{
                mp[a[i]] = {mp[a[i]].first + 1,i};
            }
        }
        int mx = 0;
        for(auto x : mp){
            mx = max(mx,x.second.first);
        }
        
        int pos = n + 1;
        pair<int,int> point = {1,1};
        for(int i=0;i<n;++i){
            if(mp[a[i]].first == mx){
                int j=mp[a[i]].second;
                int len = j-i + 1;
                //cout << i <<" "<< j <<"\n";
                if(pos > len){
                    pos = len;
                    point = {i,j};
                }
                mp.erase(a[i]);
            }
        }
        
        
        vector<int> res;
       // cout << point.first <<" "<< point.second <<"\n";
        for(int k=point.first;k<=point.second;++k){
            res.push_back(a[k]);
        }
        return res;
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
	    cin>>n; int a[n];
	    for(i=0;i<n;i++)
	    cin>>a[i];
	    vector<int > v;
	    Solution ob;
	    v = ob.smallestSubsegment(a, n);
	    for(int i:v)
	        cout<< i << " ";
	    cout<<"\n";
	}
return 0;
}
  // } Driver Code Ends