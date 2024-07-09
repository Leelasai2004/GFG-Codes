//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
		vector<string> all_longest_common_subsequences(string s, string t)
		{
		    int n=s.size(),m=t.size();
		    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
		    for(int i=1;i<=n;i++){
		        for(int j=1;j<=m;j++){
		            if(s[i-1]==t[j-1]){
		                dp[i][j]=1+dp[i-1][j-1];
		            }
		            else{
		                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		            }
		        }
		    }
		    set<string> ans;
		    queue<pair<string,pair<int,int>>> q;
		    string str="";
		    unordered_map<string,bool> mp;
		    q.push({str,{n,m}});
		    while(!q.empty()){
		        int i=q.front().second.first,j=q.front().second.second;
		        string str=q.front().first;
		        q.pop();
		        if(i==0 || j==0){
		            ans.insert(str);
		            continue;
		        }
		        string key=to_string(i)+","+to_string(j)+","+str;
		        if(mp.count(key)){
		            continue;
		        }
		        mp[key]=true;
		        if(s[i-1]==t[j-1]){
		            q.push({s[i-1]+str,{i-1,j-1}});
		        }
		        else{
		            if(dp[i-1][j]>=dp[i][j-1]){
		                q.push({str,{i-1,j}});
		            }
		            if(dp[i][j-1]>=dp[i-1][j]){
		                q.push({str,{i,j-1}});
		            }
		        }
		    }
		    return vector<string>(ans.begin(),ans.end());
		}
};



//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	string s, t;
    	cin >> s >> t;
    	Solution ob;
    	vector<string> ans = ob.all_longest_common_subsequences(s, t);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}


// } Driver Code Ends