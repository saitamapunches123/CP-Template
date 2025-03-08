/*
Usefull when you need to find LCA of many nodes. 
That is need to process many LCA(a,b) kind of querries

LCA of node a,b= node having the minimum depth in the nodes between tin[a] and tin[b]

*/

struct LCA_seg_tree{
	vector<int> euler_tour,tin,depth;
	vector<int> seg_tree;
	int time;
	LCA_seg_tree(int n){
		time=0;
		tin.assign(n+1,0);
		depth.assign(n+1,0);
		euler_tour.assign(2*(n+1),0); // as n+(n-1) thus 2*n will be enough
		seg_tree.assign(8*(n+1),0);// 4*2*(n+1) as time can go upto n
	}
	void dfs(int x,vector<vector<int>> &adj,int par=-1,int curr_depth=0){
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
		if(node1==-1) return node2; // as in querry we can get -1
		if(node2==-1) return node1;
		int d1=depth[node1],d2=depth[node2];
		if(d1<=d2)
			return euler_tour[tin[node1]];
		return euler_tour[tin[node2]];
	}
	void build(int ss,int se,int idx){
		if(ss==se){seg_tree[idx]=euler_tour[ss];
		return;}
		int mid=ss+(se-ss)/2,lc=2*idx+1,rc=2*idx+2;
		build(ss,mid,lc);
		build(mid+1,se,rc);
		seg_tree[idx]=get_min_depth_node(seg_tree[lc],seg_tree[rc]);
	}
	void build_LCA(int x,vector<vector<int>> &adj){
		dfs(x,adj);
		build(0,time-1,0);
	}
	int query(int ss,int se,int idx,int qs,int qe){
		if(qs<=ss and qe>=se)
			return seg_tree[idx];
		if(qs>se or qe<ss) return -1;
		int mid=ss+(se-ss)/2,lc=2*idx+1,rc=2*idx+2;
		int left_min_node=query(ss,mid,lc,qs,qe);
		int right_min_node=query(mid+1,se,rc,qs,qe);
		return get_min_depth_node(left_min_node,right_min_node);
	}
	int get_lca(int node1,int node2){
		//need to return node with minimum tin b/w tin of node1 and node2
		int qs=min(tin[node1],tin[node2]);
		int qe=max(tin[node1],tin[node2]);
		return query(0,time-1,0,qs,qe);
	}
};


/*

HOW TO USE?

DO FIRST!!!
LCA_seg_tree obj(n);
obj.build_LCA(1,adj); //1 root of the tree

int lca=obj.get_lca(a,b);

We can also use static RMQ over segtree if the number of queries is more than number of nodes
*/