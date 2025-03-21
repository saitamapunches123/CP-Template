/*
heavy chils the child of a node whihc has the maximum size all other nodes are light nodes
edge to a heavy node is called heavy edge 
As the number of light edges along any paths can be at most logn thus,
the number of heavy paths in any path is at most logn

thus the idea to querry over all paths is while pre_processing the tree id the nodes such that heavy child gets id first
this allows the heavy paths to have ids together 
so we can querry on these logn heavy paths tc logn*logn logn -> heavy paths and logn->for each query

so for q queries tc: qlog^2n
*/


struct HLD{
	int n,cid,base_value; //cid simillar to time in euler tour id is biased (towards headvy edge)
	vector<int> dep,id,top,sz,st,parents; // top is the top node reachable through heavy edges
	HLD(int size,int bv){ //bv base value what to return if no elements
		n=size;
		cid=0;
		base_value=bv;
		dep.assign(n,0);
		id.assign(n,0);//we query using this id
		top.assign(n,0);
		sz.assign(n,0);
		parents.assign(n,0);
		st.assign(2*n,0); //iterative segment tree using 1 based indexing
	}
	int merge(int lval,int rval){
		return max(lval,rval); //update based on the operator
	}
	void update(int idx,int val){
		idx+=n;//leaf node index
		st[idx]=val;
		while((idx/2)>=1){
			int p=idx/2;
			st[p]=merge(st[2*p],st[2*p+1]);
			idx=p;
		}
	}
	int query(int l, int r) {
		l+=n;r+=n;
		int ans=base_value;
		while(l<=r){
			if(l%2==1){
			ans=merge(ans,st[l]);//right child thus only pick the element
			l++;
			}
			if(r%2==0){
				ans=merge(ans,st[r]);//left child thun only pick the element;
				r--;
			}
			l=l/2;
			r=r/2;
		}
		return ans;
	}	
	int dfs(int curr,vector<vector<int>>&adj,int par=-1,int d=0){
		if(par==-1)
			par=curr;//marking root as its own parent
		dep[curr]=d;
		sz[curr]=1;
		parents[curr]=par;
		for(auto nxt:adj[curr]){
			if(nxt==par) continue;
			sz[curr]+=dfs(nxt,adj,curr,d+1);
		}
		return sz[curr];
	}
	void update_node(int node,int val){
		update(id[node],val);
	}
	void dfs_hld(int curr,vector<vector<int>>&adj,vector<int>& vals,int par=-1,int top_node=-1){
		if(top_node==-1)
			top_node=curr;
		id[curr]=cid;
		update_node(curr,vals[curr]);
		cid++;
		top[curr]=top_node;
		int h_node=-1;
		for(auto nxt:adj[curr]){
			if(nxt==par)continue;
			if(h_node==-1 or sz[nxt]>sz[h_node])
				h_node=nxt;
		}
		if(h_node==-1)
			return;//leaf node
		dfs_hld(h_node,adj,vals,curr,top_node);//as heavy edge so top id remains same
		for(auto nxt:adj[curr]){
			if(nxt==par or nxt==h_node) continue;
			dfs_hld(nxt,adj,vals,curr,nxt); //light edge so max reachable is this node only
		}
	}
    // light paths have top[x]=x itself
	int query_path(int x,int y){
		int ans=base_value;
		while(top[x]!=top[y]){ //while in different heavy paths
			if(dep[top[x]]<dep[top[y]])
				swap(x,y);
			int cans=query(id[top[x]],id[x]);
			ans=merge(ans,cans);
			x=parents[top[x]];
		}
		if(dep[x]<dep[y])// in same heavy path
			swap(x,y);
		ans=merge(ans,query(id[y],id[x]));
		return ans;
	}
	
};

//HOW TO USE
//PRE PROCESS
HLD obj(n+1,0);
obj.dfs(1,adj);
obj.dfs_hld(1,adj,v);

//RUN TIME
obj.update_node(node,val);
obj.query_path(l,r)