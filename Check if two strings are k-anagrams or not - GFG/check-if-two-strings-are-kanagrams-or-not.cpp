// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
    bool areKAnagrams(string str1, string str2, int k) {
        if(str1.length() != str2.length()) return 0;
        // code here
        multiset<char> st;
        
        for(auto ch : str1){
            st.insert(ch);
        }
        int cnt = 0;
        for(auto ch : str2){
            if(st.find(ch) != st.end()){
                st.erase(st.find(ch));
            }
            else{
                cnt++;
            }
        }
        if(cnt <= k) return 1;
        else return 0;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str1,str2;
		cin>>str1>>str2;
		int k;
		cin>>k;
		Solution ob;
		if(ob.areKAnagrams(str1, str2, k) == true)
			cout<<"1\n";
		else
			cout<<"0\n";
	}
}  // } Driver Code Ends