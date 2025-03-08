struct LCA_static_RMQ
{
	int sz,time;
	vector <int> tin,euler_tour,depth;
	vector<vector<int>>look_up;
	LCA_static_RMQ(int n){
		sz=n+1;
		time=0;
		tin.assign(sz,0);
		depth.assign(sz,0);
		euler_tour.assign(2*sz,0);
		int log_sz=log2(2*sz)+1;
		look_up.assign(2*sz,vector<int>(log_sz,INT_MAX));
	}
	void dfs(int x,vector<vector<int>>&adj,int par=-1,int curr_depth=0){
		depth[x]=curr_depth;
		tin[x]=time;
		euler_tour[time]=x;
		time++;
		for(auto nxt:adj[x]){
			if(nxt!=par){
				dfs(nxt,adj,x,curr_depth+1);
				euler_tour[time]=x;
				time++;
			}
		}
	}
	int get_min_depth_node(int node1,int node2){
		int d1=depth[node1],d2=depth[node2];
		if(d1<=d2)
			return node1;
		return node2;
	}
	void build(){
		int n=euler_tour.size();
		for(int i=0;i<n;i++){
			look_up[i][0]=euler_tour[i];
		}
		for(int j=1;(1<<j)<=n;j++){
			for(int i=0;(i+(1<<j)-1)<n;i++){
				look_up[i][j]=get_min_depth_node(look_up[i][j-1],look_up[i+(1<<(j-1))][j-1]);
			}
		}
	}
	void build_LCA(int x,vector<vector<int>>& adj){
		dfs(x,adj);
		build();
	}
	int query(int l,int r){
		int w=r-l+1;
		int maxj=log2(w);
		int ans1=look_up[l][maxj];
		int start_end=r-(1<<maxj)+1;
		int ans2=look_up[start_end][maxj];
		return get_min_depth_node(ans1,ans2);
	}
	int get_lca(int node1,int node2){
		//need to return node with minimum depth b/w tin of node1 and node2
		int qs=min(tin[node1],tin[node2]);
		int qe=max(tin[node1],tin[node2]);
		return query(qs,qe);
	}
	int get_dist(int node1,int node2){
		int lca_node=get_lca(node1,node2);
		return depth[node1]+depth[node2]-2*depth[lca_node];
	}
};