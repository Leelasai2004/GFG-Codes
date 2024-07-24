//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& nums) {
    //   vector<int> x;
    //   vector<int> inserted(n);
    //     x.push_back(nums[0]);
    //     for(int i=1;i<nums.size();i++){
    //         if(x.back()<nums[i]){
    //             x.push_back(nums[i]);
    //             inserted[i]=x.size();
    //         }
    //         else{
    //             auto it=lower_bound(x.begin(),x.end(),nums[i]);
    //             inserted[i]=it-x.begin();
    //             *it=nums[i];
    //         }
    //     }
    //     int l=x.size();
    //     vector<int> ans;
    //     map<int,int> mp;
        vector<int> dp(n+1,1),hash(n);
        for(int i=0;i<n;i++){
            hash[i]=i;
        }
        int last=0,mxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i] && dp[j]+1>dp[i]){
                    dp[i]=1+dp[j];
                    hash[i]=j;
                }
            }
            if(dp[i]>mxi){
                mxi=dp[i];
                last=i;
            }
        }
        vector<int> ans;
        ans.push_back(nums[last]);
        while(hash[last]!=last){
            last=hash[last];
            ans.push_back(nums[last]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        vector<int> res = obj.longestIncreasingSubsequence(N, arr);
        for (auto x : res)
            cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends