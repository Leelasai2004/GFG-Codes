//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


// } Driver Code Ends
class Solution
{
    public:
    void merge(int arr[], int l, int m, int r)
    {
        
         int temp[r-l+1];
         int i=0;
         int s=l,e=r;
         int x=m;
         int y=m+1;
         while(l<=x && y<=r){
             if(arr[l]<=arr[y]){
                 temp[i]=arr[l];
                 i++;
                 l++;
             }
             else{
                 temp[i]=arr[y];
                 y++;
                 i++;
             }
             
         }
         while(l<=x){
             temp[i]=arr[l];
             l++;
             i++;
         }
         while(y<=r){
             temp[i]=arr[y];
             i++;
             y++;
         }
         i=0;
         for(int j=s;j<=e;j++){
             arr[j]=temp[i];
             i++;
         }
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        if(l>=r){
            return;
        }
        int m=(l+r)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
};

//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends