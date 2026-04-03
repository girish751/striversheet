class Solution {
public:
    bool isBipartiteHelper(vector<vector<int>>& graph,int src,vector<bool>& vis,vector<int>& colour) {
        queue<int> q;
        colour[src]=0;
        q.push(src);
        vis[src]=true;
        
        while(!q.empty()){
            int curr=q.front();
            q.pop();

            vector<int> neighbours=graph[curr];

            for(auto v:neighbours){

                if(!vis[v]){
                    q.push(v);
                    vis[v]=true;
                    colour[v]= !colour[curr];
                }

                else{
                    if(colour[v]==colour[curr]){
                        return false;
                    }
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph){
        int V=graph.size();
        vector<bool> vis(V,false);
        vector<int> colour(V,-1);

        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(!isBipartiteHelper(graph,i,vis,colour)){
                    return false;
                }
            }
        }
        return true;
    }
};