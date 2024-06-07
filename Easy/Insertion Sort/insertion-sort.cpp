//{ Driver Code Starts
// C program for insertion sort
#include <stdio.h>
#include <math.h>

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
    void insert(int arr[], int i,int n)
    {
       if(i==n){
           return ;
       }
       int j=i-1;
       int temp=arr[i];
       while(j>=0 && arr[j]>temp){
           arr[j+1]=arr[j];
           j--;
       }
       arr[j+1]=temp;
       insert(arr,i+1,n);
        
        
    }
     public:
    //Function to sort the array using insertion sort algorithm.
    void insertionSort(int arr[], int n)
    {
        insert(arr,1,n);
    }
};

//{ Driver Code Starts.
int main()
{
    int arr[1000],n,T,i;

    scanf("%d",&T);

    while(T--){

    scanf("%d",&n);

    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.insertionSort(arr, n);
    printArray(arr, n);
    }
    return 0;
}

// } Driver Code Ends