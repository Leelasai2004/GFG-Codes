//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int mod=1e9+7;
    int countPartitions(int n, int d, vector<int>& v) {
         int max_sum=0;
    for(int i=0;i<n;i++) {max_sum+=v[i];}
    if((max_sum-d)&1 || max_sum<d){
        return 0;
    }
    vector<vector<int>> dp(n+1,vector<int>(max_sum+1,0));
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        dp[i][0]=1;
        for(int curr=0;curr<=max_sum;curr++){
           
            if(v[i-1]<=curr && dp[i-1][curr-v[i-1]]){
                dp[i][curr]=(dp[i-1][curr]+dp[i-1][curr-v[i-1]])%mod;
            }
            else{
                dp[i][curr]=dp[i-1][curr];
            }
        }
    }
    // cout<<dp[1][5]<<'\n';
    return dp[n][(max_sum-d)/2]%mod;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends