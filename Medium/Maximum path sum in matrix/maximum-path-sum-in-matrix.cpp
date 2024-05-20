//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
      int solve(vector<vector<int>> &arr,int i,int j,int N,vector<vector<int>>& dp){
       
        if(j<0 || j>N) return INT_MIN; 
        if(i==0) return arr[i][j];
        
        if( dp[i][j] != -1) return  dp[i][j];
        
        int up=arr[i][j]+solve(arr,i-1,j,N,dp);
        int cross1=arr[i][j]+solve(arr,i-1,j-1,N,dp);
        int cross2=arr[i][j]+solve(arr,i-1,j+1,N,dp);
        
        return dp[i][j] = max(up,max(cross1,cross2));
    }
  

    int maximumPath(int N, vector<vector<int>> Matrix)
    {
     
      int mx=0;
      vector<vector<int>> dp(N,vector<int>(N,-1));
      
      for(int i=N-1; i>=0; i--){
        int ans=  solve(Matrix,N-1,i,N-1,dp);
        mx=max(mx,ans);
      }  
      
      return mx;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends