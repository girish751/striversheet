class Solution {
public:
    bool dfs(int curr, int parent,
             vector<vector<int>>& adj,
             vector<int>& vis,
             vector<int>& path,
             vector<int>& cycle,
             bool &found){
        vis[curr] = 1;
        path.push_back(curr);
        for(int nxt: adj[curr]){
            if(!vis[nxt]){
                if(dfs(nxt, curr, adj, vis, path, cycle, found))
                    return true;
            }
            else if(vis[nxt]==1){
                found = true;
                auto it = find(path.begin(), path.end(), nxt);
                for(; it!=path.end(); it++){
                    // convert back to 1-based
                    cycle.push_back(*it + 1);
                }
                return true;
            }
        }
        vis[curr] =2;
        path.pop_back();
        return false;
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int>ind(n,0);
        vector<vector<int>> adj(n);
        for(auto &e : edges){
            int u = e[0]-1;
            int v = e[1]-1;
            ind[v]++;
            adj[u].push_back(v);
        }
        // only one node will have indegree = 2
        int nodee = -1;
        for(int i=0;i<n;i++){
            if(ind[i]>1){
                nodee = i+1;
            }
        }
        vector<int> vis(n,0), path, cycle;
        bool found = false;
        for(int i = 0; i < n && !found; i++){
            if(!vis[i]){
                dfs(i, -1, adj, vis, path, cycle, found);
            }
        }
        if(found){
            // cycle exists
        vector<pair<int,int>> vpp;
        for(int i = 0; i + 1 < (int)cycle.size(); i++){
            vpp.push_back({cycle[i], cycle[i+1]});
        }
        vpp.push_back({cycle.back(), cycle.front()});
        int maxi = -1;
        vector<int> answer(2, -1);
        for(auto &p : vpp){
            int a = p.first, b = p.second;
            for(int i = 0; i < (int)edges.size(); i++){
                int x = edges[i][0], y = edges[i][1];
                if( (x == a && y == b)){
                    if(i > maxi){
                        maxi = i;
                        answer[0] = x;
                        answer[1] = y;
                    }
                }
            }
          }
          if(nodee==-1){
            // means only cycle
            return answer;
          }
          else{
            // means both cycle and indegree of a node == 2
            // remove that cycle node : 
            vector<int>anss(2,-1);
            for(auto &p:vpp){
                int a = p.first;int b = p.second;
                if(b==nodee){
                    anss[0] = a;
                    anss[1] = b;
                    break;
                }
            }
            return anss;
          }
        }
        else{
            // no cycle
            vector<int>ans(2,-1);
            for(auto i:edges){
                int u = i[0];
                int v = i[1];
                if(v==nodee){
                    ans[0] = u;
                    ans[1] = v;
                }
            }
            return ans;
        }
        
    }
};