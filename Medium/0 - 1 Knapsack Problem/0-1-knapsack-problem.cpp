//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int w, int wt[], int val[], int n) 
    { 
        vector<vector<int>> dp(n+1,vector<int>(w+1,0));
        dp[0][0]=0;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=w;j++){
                // cout<<"#x "<<i<<" "<<j<<" "<<dp[i-1][j]<<'\n';
    
                if(j+wt[i-1]<=w && (dp[i-1][j]!=0 || j==0)){
                    // cout<<j+wt[i-1]<<" "<<dp[i-1][j]+val[i-1]<<'\n';
                    dp[i][j+wt[i-1]]=max(dp[i-1][j+wt[i-1]],dp[i-1][j]+val[i-1]);
                    // cout<<dp[i][j+wt[i-1]]<<'\n';
                    
                }
                dp[i][j]=max(dp[i-1][j],dp[i][j]);
            //   cout<<"#y "<<i<<" "<<j<<" "<<dp[i][j]<<'\n';
            }
        }
        return *max_element(dp[n].begin(),dp[n].end());
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends