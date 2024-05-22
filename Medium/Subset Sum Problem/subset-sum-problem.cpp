//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        int max_sum=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            max_sum+=arr[i];
        }
        vector<vector<int>> dp(n+1,vector<int>(max_sum+1,0));
        for(int i=0;i<n;i++) dp[i][0]=true;
        for(int i=0;i<n;i++) dp[i][arr[i]]=true;
        for(int i=0;i<n;i++){
           for(int j=0;j<=max_sum;j++){
               if(j-arr[i]>=0){
                   if(i>=1) dp[i][j]=dp[i-1][j] | dp[i-1][j-arr[i]];
               }
               else{
                   if(i>=1)dp[i][j]= dp[i-1][j];
               }
           }
        }
        return (sum<=max_sum)?dp[n-1][sum]:0;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends