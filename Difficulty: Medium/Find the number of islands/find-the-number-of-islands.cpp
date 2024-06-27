//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    // Function to find the number of islands.
    void Serase(vector<vector<char>> &grid,int i,int j){
        int n=(int)grid[0].size();
        int m=grid.size();
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j]=='0'){
            return ;
        }
        grid[i][j]='0';
        Serase(grid,i-1,j);
        Serase(grid,i+1,j);
        Serase(grid,i,j+1);
        Serase(grid,i,j-1);
        Serase(grid,i-1,j-1);
        Serase(grid,i+1,j+1);
        Serase(grid,i+1,j-1);
        Serase(grid,i-1,j+1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=n?grid[0].size():0;
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    ans++;
                    Serase(grid,i,j);
                }
            }
        }
        return ans;
    }

};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends