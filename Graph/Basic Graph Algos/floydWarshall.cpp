/*
Djisktra -> doesnt work if graph has negative weights single source O(Nlogm)
Bellman Ford -> works if graph has negative weights and detects negative weight cycles single source o(n*m)
Floyd Warshall -> works if graph has negative weights and doesnt detect negative weight cycles multi source o(n^3)

To get the shortest path between all pairs of vertices in a graph.
If graph has negative weights can use n djisktra n*n*logm
but if graph has negative weights can use floyd warshall n^3
*/

bool floyd_warshall(vector<vector<ll>> &dist) {
    int n=dist.size();
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j]=min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (dist[i][i] < 0) {
            // cout << "Negative cycle detected at node " << i << "\n";
          return false;
        }
    }
  return true;
}
