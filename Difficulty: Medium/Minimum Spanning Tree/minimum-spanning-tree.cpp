//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    
// Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adji[]) {
        // code here
        int v,e;
    //cin>>v>>e;
    v=V;
    // e=adji.size();
    map<int,vector<pair<int,int>>>adj;
    vector<pair<int,int>>mst_edges;
    // for(int i=0;i<e;i++){
    //   int e1,e2,wt;
    //   //cin>>e1>>e2>>wt;
    //   e1=adji[i][0];
    //   e2=adji[i][1];
    //   wt=adji[i][2];
    //   adj[e1].push_back({e2,wt});
    //   adj[e2].push_back({e1,wt});
    // }
    for(int i=0;i<V;i++){
        for(auto j:adji[i]){
            int e1,e2,wt;
            e1=j[0];
             wt=j[1];
             adj[i].push_back({e1,wt});
            adj[e1].push_back({i,wt});
        }
    }
    int sum=0;
    vector<int>vis(v,0);
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;

    // initially push node 0 with parent -1 and weight 0
    pq.push({0,{0,-1}});// wt , node , parent
    while(!pq.empty()){
      int len,node,parent;
      len=pq.top().first;
      node=pq.top().second.first;
      parent=pq.top().second.second;
      pq.pop();
      // always check whether it is unvisted or not and then proceed

      if(vis[node]==0){
         vis[node]=1; // mark the node as visited

         sum+=len; // add the weight to the total sum

         // push every edge apart from the starting dummy one 
         if(parent!=-1){
            mst_edges.push_back({node,parent}); // add the edges to the minimum spanning tree edge vector
         } 

         // going through the adj list 
         for(int i=0;i<adj[node].size();i++){
            int too,cost;
            too=adj[node][i].first;
            cost=adj[node][i].second;

            // push it into the PQ only if it is unvisited
            if(vis[too]==0){
               pq.push({cost,{too,node}});
            }
         }
      }
    }
    return sum;
    }

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }

        Solution obj;
        cout << obj.spanningTree(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends