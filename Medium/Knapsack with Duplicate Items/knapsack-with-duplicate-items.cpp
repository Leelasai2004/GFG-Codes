//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<int> dp(W+1,0);
        for(int i=1;i<=W;i++){
            for(int j=0;j<N;j++){
                int w=wt[j],v=val[j];
                if(i-w>=0){
                    dp[i]=max(dp[i],dp[i-w]+v);
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends