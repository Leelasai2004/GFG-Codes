//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    int mod=1e9+7;
	public:
	int perfectSum(int arr[], int n, int sum)
	{
	   // sum=9;
        vector<vector<int>> dp(n+1,vector<int>(sum+1,0));
        dp[0][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=sum;j++){
                if(j>=arr[i-1]){
                    // if(i==1 && j==sum){
                    //     cout<<dp[i-1][j-arr[i-1]]<<'\n';
                    //     cout<<dp[i-1][j]<<'\n';
                    // }
                    if(dp[i-1][j-arr[i-1]]>0){
                        dp[i][j]=(dp[i-1][j]+dp[i-1][j-arr[i-1]])%mod;
                    }
                    else{
                        dp[i][j]=dp[i-1][j];
                    }
                }
                else{
                    dp[i][j]=max(dp[i][j],dp[i-1][j]);
                }
            }
        }
        // for(int i=1;i<=n;i++){
        //     cout<<dp[i][9]<<" ";
        // }
        return dp[n][sum]%mod;
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends