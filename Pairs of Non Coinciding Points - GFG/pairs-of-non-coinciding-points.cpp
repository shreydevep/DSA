// { Driver Code Starts


#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;

 // } Driver Code Ends


class Solution {
  public:
    map<int,int> same_X;
    map<int,int> same_Y;
    map<pair<int,int>,int> same_X_Y;
    int numOfPairs(int X[], int Y[], int N) {
        // code here
        int ans = 0;
        int rem = 0;
        for(int i=0;i<N;++i){
            same_X[X[i]]++;
            same_Y[Y[i]]++;
            if(same_X_Y.find({X[i],Y[i]}) != same_X_Y.end()){
                rem += same_X_Y[{X[i],Y[i]}];
            }
            else{
                same_X_Y[{X[i],Y[i]}]++;
            }
        }
        for(auto x : same_X){
            ans += ((x.second)*(x.second-1))/2;
        }
        
        for(auto x : same_Y){
            ans += ((x.second)*(x.second-1))/2;
        }
        
        return ans -2*rem;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        int X[N], Y[N];
        
        for(int i=0; i<N; i++)
            cin>>X[i];
        for(int i=0; i<N; i++)
            cin>>Y[i];

        Solution ob;
        cout << ob.numOfPairs(X,Y,N) << endl;
    }
    return 0;
}  // } Driver Code Ends