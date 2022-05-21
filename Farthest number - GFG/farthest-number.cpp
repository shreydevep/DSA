// { Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution{   
  public:
    vector<int> farNumber(int N,vector<int> Arr){
        vector<pair<int,int>> v;
        for(int i=0;i<N;++i){
            v.push_back({Arr[i],i});
        }
        sort(v.begin(),v.end());
        vector<int> ans;
        int dis = -1;
        for(int i=0;i<N;++i){
            if(dis == -1){
                v[i].first = -1;
            }
            else{
                if(dis > v[i].second){
                   v[i].first = dis;
                }
                else{
                    v[i].first = -1;
                }
            }
           dis = max(dis,v[i].second);
        }
        for(int i=0;i<N;++i){
            Arr[v[i].second] = v[i].first;
        }
        return Arr;
        
    }
};

// { Driver Code Starts.
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        vector<int> Arr(N);
        for(int i=0;i<N;i++)
            cin>>Arr[i];
        Solution obj;
        vector<int> answer=obj.farNumber(N,Arr);
        for(auto i:answer)
            cout<<i<<" ";
        cout<<endl;
  }
}  // } Driver Code Ends