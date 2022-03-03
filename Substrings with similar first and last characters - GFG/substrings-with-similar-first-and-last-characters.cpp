// { Driver Code Starts
 
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	

	int countSubstringWithEqualEnds(string s)
	{
	    // Your code goes here
	    vector <int> freq[26];
	    for(int i=0;i<s.length();++i){
	        freq[s[i]-'a'].push_back(i);
	    }
	    int ans = 0;
	    for(int i=0;i<26;++i){
	        for(int j=0;j<freq[i].size();++j){
	            for(int k=j;k<freq[i].size();++k){
	                    ans++;
	            }
	        }
	    }
	    return ans;
	}
};

// { Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string str;
   		cin >> str;

   	    Solution ob;

   		cout << ob.countSubstringWithEqualEnds(str) << "\n";
   	}

    return 0;
}  // } Driver Code Ends