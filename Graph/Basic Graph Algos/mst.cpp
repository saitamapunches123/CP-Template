/*
MST-> minimum spanning tree is usefull to convert a connected graph to a tree with v vertices and v-1 edges.alignas
The idea is to find the mimimum weight of the tree.
*/

//TWO ALGOS can be used

/*
PRIMS
Prim's algorithm works by adding smallest edge form connected to not connected component.
*/
int prims(vector<vector<pair<int,int>>>&adj){
    int n=adj.size();
    vector<bool> vis(n,false);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,0});//change this based on if 0 is in graph or not 
    int ans=0;
    while(pq.size()>0){
        auto [u,wt]r=pq.top();pq.pop();
        if(vis[u])
        continue;
        ans+=wt;
        vis[u]=true;
        for(int i=0;i<adj[u].size();i++){
            int v=adj[u][i].first,ewt=adj[u][i].second;
            if(vis[v]==false)
            pq.push({ewt,v});
        }
    }
    return ans;
}
//TC o(v+e(log v))




/*
KRUSKAL:
KRUSKAL's algorithm sorts the edges by weight and tahn pick the smallest v-1 edges ucht that each edge doesnt form a cycle
*/