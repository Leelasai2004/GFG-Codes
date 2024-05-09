//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int helper(vector<vector<int>>& points,vector<vector<int>> &dp,int n,int task){
        if(dp[n-1][task]!=-1){
            return dp[n-1][task];
        }
        int maxi=INT_MIN;
        for(int i=0;i<=2;i++){
            if(task!=i){
                maxi=max(maxi,points[n-1][i]+helper(points,dp,n-1,i));
            }
        }
        return dp[n-1][task]=maxi;
    }
    int maximumPoints(vector<vector<int>>& points, int n) {
        // Code here
        vector<vector<int>> dp(n,vector<int>(4,-1));
        dp[0][0]=max(points[0][1],points[0][2]);
        dp[0][1]=max(points[0][2],points[0][0]);
        dp[0][2]=max(points[0][0],points[0][1]);
        dp[0][3]=max(dp[0][0],max(dp[0][1],dp[0][2]));
        // return helper(points,dp,n,3);
        for(int i=1;i<n;i++){
            for(int task=0;task<=2;task++){
              dp[i][0]=max(points[i][1]+dp[i-1][1],points[i][2]+dp[i-1][2]);
              dp[i][1]=max(points[i][0]+dp[i-1][0],points[i][2]+dp[i-1][2]);
              dp[i][2]=max(points[i][0]+dp[i-1][0],points[i][1]+dp[i-1][1]);
            }
        }
        return max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2]));
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> points;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            points.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(points, n) << endl;
    }
    return 0;
}
// } Driver Code Ends