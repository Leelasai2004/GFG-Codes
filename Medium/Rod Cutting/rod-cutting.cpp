//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int cutRod(int price[], int n) {
        vector<int> dp(n+1,0);
        int w=n;
        for(int i=1;i<=w;i++){
            for(int j=0;j<n;j++){
                int val=price[j],wt=j+1;
                if(i-wt>=0){
                    dp[i]=max(dp[i],dp[i-wt]+val);
                }
            }
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
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends