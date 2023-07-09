//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
        
    	// Your code here
    	// arr[]sorted 
    	// dep[sorted]
    	 // i = 1 and j = 0 taki pehla train chod de.
    	// now  we have to check if arr[i]<=dep[i]
    	// if the above condition is true then we have to add the platform count 
    	// else arr[i]> dep[i] matlab we can use a empty platform and we can subtract the count
    	
    // 	0900 0940 0950 1100 1500 1800
    //  0910 1120 1130 1200 1900 2000
    	sort(arr,arr+n);
    	sort(dep,dep+n);
    	int i = 1,j  = 0;
    	int count = 1; 
    	int ans = 1;
    	while (i< n&& j < n)
    	{
    	    if(arr[i]<= dep[j] )
    	    {
    	        count++;
    	        
    	        i++;
    	    }
    	    else 
    	    {
    	        count--;
    	        j++;
    	    }
    	    ans = max(count,ans);
    	}
    	return ans;
    }
};


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends