//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	const int mod=(int)1e9+7;
	int numberOfPermWithKInversion(int N, int K)
	{
        vector<vector<int>> dp(N+1,vector<int>(K+1,0));
        dp[0][0]=1;
        for(int i=1;i<=N;i++){
            long long curr=0;
            for(int j=0;j<=K;j++){
                curr+=dp[i-1][j];
                if(j>=i) curr-=dp[i-1][j-i];
                dp[i][j]=curr%mod;
            }
        }
        return dp[N][K];
 	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;

        

	    Solution ob;
	    cout << ob.numberOfPermWithKInversion(n, k) << "\n";
	     
    }
    return 0;
}





// } Driver Code Ends