// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	string fractionToDecimal(int n, int d) {
    string ans;
    int q=floor(n/d);
    int r=n%d;
    ans+=to_string(q);
    if(r==0){
        return ans;    
    }
    ans+=".";
    
    map<int,int>mp;
    while(r!=0){
    if(mp.find(r)!=mp.end()){
           int len=mp[r];
           ans.insert(len,"(");
           ans+=")";
           return ans;
    }
    else{
        mp.insert(pair<int,int>(r,ans.length()));
        r*=10;
        q=floor(r/d);
        r%=d;
        ans+=to_string(q);
    }
    }
}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int numerator, denominator;
		cin >> numerator >> denominator;
		Solution ob;
		string ans = ob.fractionToDecimal(numerator, denominator);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends