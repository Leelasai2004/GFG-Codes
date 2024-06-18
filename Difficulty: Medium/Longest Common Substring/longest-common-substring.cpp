//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    
    int longestCommonSubstr (string s, string t, int n, int m)
    {
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                    if(i==1 || j==1){
                        dp[i][j]=1;
                    }
                    else{
                        if(s[i-2]==t[j-2]){
                            dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
                        }
                        else{
                            dp[i][j]=1;
                        }
                    }
                }
               
            }
        }
        int ans=0;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                ans=max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends