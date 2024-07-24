//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int nums[])
    {
  vector<int> x;
      vector<int> inserted(n);
        x.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(x.back()<nums[i]){
                x.push_back(nums[i]);
                inserted[i]=x.size();
            }
            else{
                auto it=lower_bound(x.begin(),x.end(),nums[i]);
                inserted[i]=it-x.begin();
                *it=nums[i];
            }
        }
        reverse(x.begin(),x.end());
        return x.size();
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends