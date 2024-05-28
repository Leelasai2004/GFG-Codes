//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool isSubsetSum(vector<int>v, int sum){
      
    int n=v.size();
     int max_sum=0;
    for(int i=0;i<n;i++) {max_sum+=v[i];}
    vector<vector<int>> dp(n+1,vector<int>(max_sum+1,0));
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        dp[i][0]=1;
        for(int curr=0;curr<=max_sum;curr++){
            dp[i][curr]=max(dp[i][curr],dp[i-1][curr]);
            if(dp[i-1][curr]!=0){
                dp[i][curr+v[i-1]]=1;   //push_dp
            }
        }
    }
    // int ans=0;
    // for(int i=0;i<=max_sum;i++){
    //     if(dp[n][i]==0) continue;
    //     if(__builtin_popcountll(i)==k){
    //         // cout<<i<<'\n';
    //         ans++;
    //     }

    // }
    return (sum<=max_sum)?dp[n][sum]:0;
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