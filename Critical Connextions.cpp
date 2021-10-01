vector<vector<int>> ans;
int vis[100003];
int tin[100003];
int low[100003];
int timer;
class Solution {
public:
    /*
see cp-algo for explainations
*/
    void dfs(vector<vector<int>> &adj,int x,int par=-1)
    {
        tin[x]=timer++;
        low[x]=tin[x];
        vis[x]=1;
        for(auto j:adj[x])
        {
            if(j==par)
                continue;
            if(vis[j]==1)
            {
                low[x]=min(low[x],tin[j]);
            }
            else
            {
                dfs(adj,j,x);
                low[x]=min(low[x],low[j]);
                if(low[j]>tin[x])
                    ans.push_back({x,j});
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(auto j:connections)
        {
            adj[j[0]].push_back(j[1]);
            adj[j[1]].push_back(j[0]);
        }
        timer=0;
        ans.clear();
        memset(vis,0,sizeof(vis));
        memset(tin,-1,sizeof(tin));
        memset(low,-1,sizeof(low));
        dfs(adj,0);
        return ans;
    }
};
