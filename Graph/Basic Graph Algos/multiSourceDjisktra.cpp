/*
NOTE: Djisktra finds  single source multiple traget shortest distance i.e dist[v] is distance of v from the source
but it can also be used in opposite wat that is multisource single single target shortest distance.


We can do this in 2 way let the set of sources be S={s1,s2,s3,s4,s5,...}
and target be t
we can reverse the edges and run djisktra from t to get the answer=min(dist[s1],dist[s2],dist[s3],dist[s4],dist[s5],...)
or 
we can insert all the sources in the priority queue and run djisktra from all the sources to get the answer=dist[t]
*/

vector<ll> dijkstra_multi_source(vector<vector<pair<ll,ll>>> &adj,vector<int> &sources) {
    int n=adj.size();
    const ll INF = LLONG_MAX;
    vector<ll> dist(n, INF);

    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;

    for (int s : sources) {
        dist[s] = 0;
        pq.push({0, s});
    }

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d != dist[u]) continue;

        for (auto &edge : adj[u]) {
            int v = edge.first;
            ll w = edge.second;

            if (dist[v] > d + w) {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}