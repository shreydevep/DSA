// { Driver Code Starts
// C++ implementation to check whether the array
// contains a set of contiguous integers
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    // Function to check whether the array contains
    // a set of contiguous integers
    bool areElementsContiguous(int arr[], int n)
    {
	// Complete the function
	    set<int> st;
	    for(int i=0;i<n;++i){
	        st.insert(arr[i]);
	    }
	    
	    auto vbegin = *st.begin();
	    auto vend = *(st.rbegin());
	    int curr = 0;
	    //cout << vbegin <<" "<< vend <<"\n";
	    for(int i=vbegin;i<=vend;++i){
	        //cout << i <<"\n";
	        if(st.find(i) == st.end()) {
	           return 0;
	        }
	    }
	    return 1;
	    
    }
};

// { Driver Code Starts.
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        int arr[n + 1];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        if (ob.areElementsContiguous(arr, n))
            cout << "Yes" <<endl;
        else
            cout << "No" <<endl;
    }
	return 0;
}
  // } Driver Code Ends