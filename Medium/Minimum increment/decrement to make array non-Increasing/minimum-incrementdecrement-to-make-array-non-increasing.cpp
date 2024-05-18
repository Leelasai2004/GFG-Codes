//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>

using namespace std;



// } Driver Code Ends



class Solution{
public:
    int minOperations(int *a,int n)
    {
        int sum = 0, dif = 0;
 
    // min heap
    priority_queue<int, vector<int>, greater<int> > pq;
 
    // Here in the loop we will check that whether
    // the top of priority queue is less than
    // the upcoming array element. If yes then
    // we calculate the difference. After that
    // we will remove that element and push the
    // current element in queue. And the sum
    // is incremented by the value of difference
    for (int i = 0; i < n; i++) {
        if (!pq.empty() && pq.top() < a[i]) {
            dif = a[i] - pq.top();
            sum += dif;
 
            // Removing that minimum element
            // which does follow the decreasing
            // property and replacing it with a[i]
            // to maintain the condition
            pq.pop();
            pq.push(a[i]);
        }
 
        // Push the current element as well
        pq.push(a[i]);
    }
 
    return sum;
    }
};

//{ Driver Code Starts.

int main() {
    
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int  a[n+1];
        for(int i=0;i<n;i++)
            cin>>a[i];
            
        Solution ob;
        cout<<ob.minOperations(a,n)<<endl;
    }
    
	return 0;
}
// } Driver Code Ends