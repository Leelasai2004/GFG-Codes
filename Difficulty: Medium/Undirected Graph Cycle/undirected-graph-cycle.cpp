//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool dfs(int u,int par,vector<int> adj[],vector<int> &vis){
        vis[u]=2;
        bool ok=true;
        for(auto v:adj[u]){
            if(v!=par){
            if(vis[v]==2){
                return false;
            }
            if(vis[v]==0){
                ok&=dfs(v,u,adj,vis);
            }
        }
           
        }
        vis[u]=1;
        return ok;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V,0);
        bool f=true;
        for(int i=0;i<V;i++){
            if(vis[i]==0){
               f=f & dfs(i,-1,adj,vis);
               if(!f){
                   return true;
               }
            }
            
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends