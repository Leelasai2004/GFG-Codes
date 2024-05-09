//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
#define mod 1000000007
int x=0;
class Solution {
  public:
    long long int climb(int n,vector<long long int> &dp2){
      
       if(n==0){
           return 0;
       }
       if(n==1) return 1;
       if(dp2[n]!=-1){
           return dp2[n];
       }
       return dp2[n]=(climb(n-2,dp2)+climb(n-1,dp2))%mod;
    }
    long long int topDown(int n) {
      vector<long long int> dp2(n+1,-1);
      dp2[0]=0;
      dp2[1]=1;
      return climb(n,dp2);
    }
    long long int bottomUp(int n) {
        vector<long long int> dp(n+1,0);
        dp[0]=0,dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=(dp[i-1]+dp[i-2])% mod;
        }
        return dp[n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        long long int topDownans = obj.topDown(n);
        long long int bottomUpans = obj.bottomUp(n);
        if (topDownans != bottomUpans) cout << -1 << "\n";
        cout << topDownans << "\n";
    }
}
// } Driver Code Ends