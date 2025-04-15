/*
problem with djisktra:
Doesnt detect negative weight cycles 
so if the graph has negative weight it can have negative weight cycle 
so use bellman ford.

The idea behind bellman ford is that the shortest simple path between any pair of vertex can have at most v-1 edges
if it has more than v-1 edges that means the shortest path has an cycle (which only makes sense for negative weight cycle)
*/

vector<int> bellmanFord(vector<vector<pair<int,int>>>&adj,int src) {
    int n=adj.size();
    vector<int> dists(n,INT_MAX);
    dists[src]=0;
    bool is_relaxed=true;
    for(int i=0;i<n;i++){
        is_relaxed=false;
        for(int u=0;u<n;u++){
            auto [v,w]=adj[u];
            if(dists[u]!=INT_MAX and dists[u]+w<dists[v]){
                dists[v]=dists[u]+w;
                is_relaxed=true;
            }
        }
        if(is_relaxed==false)//no more changes 
        return dists;
    }
    return {-1};   //changes even on nth turn so negative cycle
}

//TC: O(n*e)=o(n^3) as e can be upto n^2