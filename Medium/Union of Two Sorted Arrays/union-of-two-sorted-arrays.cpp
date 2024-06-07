//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //arr1,arr2 : the arrays
    // n, m: size of arrays
    //Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        vector<int> ans;
        int l=0,r=0;
        while(l<n && r<m){
            if(arr1[l]<=arr2[r]){
                ans.push_back(arr1[l]);
    
                while(arr2[r]==arr1[l]){
                    r++;
                }
                int temp=arr1[l];
                while(arr1[l]==temp){
                    l++;
                }
            }
            else if(arr1[l]>arr2[r]){
                ans.push_back(arr2[r]);
              int temp=arr2[r];
                while(arr2[r]==temp){
                    r++;
                }
                // r++;
                
            }
        }
        while(l<n){
            ans.push_back(arr1[l]);
              int temp=arr1[l];
                while(arr1[l]==temp){
                    l++;
                }
        }
        while(r<m){
            ans.push_back(arr2[r]);
            // r++;
             int temp=arr2[r];
                while(arr2[r]==temp){
                    r++;
                }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--){
	    
	    
	    
	    int N, M;
	    cin >>N >> M;
	    
	    int arr1[N];
	    int arr2[M];
	    
	    for(int i = 0;i<N;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<M;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    vector<int> ans = ob.findUnion(arr1,arr2, N, M);
	    for(int i: ans)cout<<i<<' ';
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends