//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        unordered_map<int,int> mp;
        int n=N;
        int l=0,r=0;
        int sum=0;
        mp[0]=-1;
        int ans=0;
        while(r<n){
            sum+=A[r];
            int req=sum-K;
            if(mp.find(req)!=mp.end()){
                ans=max(ans,r-mp[req]);
            }

            if(mp.find(sum)==mp.end()){
                mp[sum]=r;
            }
            r++;
        }
        return ans;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends