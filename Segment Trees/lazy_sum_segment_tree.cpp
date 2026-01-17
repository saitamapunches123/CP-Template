/* 
	lazy sum tree
	1) range add (add x to [qs,qe])
	2) range sum
*/
struct Lazy_Seg_Tree{
	struct Node{
		ll sum=0;// When at a node its sum should be correct i.e all ancestors must push before
		ll lazy=0;
	};
	int n;
	vector<Node> tree;
	Lazy_Seg_Tree(int m){
		n=m;
		tree.assign(4*n,Node());
	}
	void apply(int node,int ss,int se,ll x){ //apply x to tree[i]
		ll len=se-ss+1;
		tree[node].sum+=len*x;
		tree[node].lazy+=x;
	}
	void push(int node,int ss,int se){ // make lazy[i]=0 i.e push its changes to children
		if(ss!=se){
			int m=(ss+se)/2;
			ll x=tree[node].lazy;
			apply(2*node,ss,m,x);
			apply(2*node+1,m+1,se,x);
		}
		tree[node].lazy=0;
	}
	void update(int node,int ss,int se,int qs,int qe,ll x){ //add x to [qs,qe] range
		if(qe<ss or qs>se)
			return;
		if(qs<=ss and qe>=se){
			apply(node,ss,se,x);
			return;
		}
		push(node,ss,se); // push changes to children before going to them
		int m=(ss+se)/2,lc=2*node,rc=2*node+1;
		update(lc,ss,m,qs,qe,x);
		update(rc,m+1,se,qs,qe,x);
		tree[node].sum=tree[lc].sum+tree[rc].sum;
	}
	ll query(int node,int ss,int se,int qs,int qe){ //get sum of x PS: WHEN at node i we have correct/updated sum of range [qs,qe]
		if(qe<ss or qs>se)
			return 0;
		if(qs<=ss and qe>=se)
			return tree[node].sum;
		push(node,ss,se); // push changes to children before going to them
		int m=(ss+se)/2,lc=2*node,rc=2*node+1;
		return query(lc,ss,m,qs,qe)+query(rc,m+1,se,qs,qe);
	}
	void update(int qs,int qe,int x){
		return update(1,0,n-1,qs,qe,x);
	}
	ll query(int qs,int qe){
		return query(1,0,n-1,qs,qe);
	}
};



/* 
	lazy sum tree
	1) range set (set [qs,qe] to x)
	2) range sum
*/
struct Lazy_Seg_Tree{
	struct Node{
		ll sum=0;// When at a node its sum should be correct i.e all ancestors must push before
		ll lazy=LLONG_MIN;// using LLONG_MIN as sentinal value.
	};
	int n;
	vector<Node> tree;
	Lazy_Seg_Tree(int m){
		n=m;
		tree.assign(4*n,Node());
	}
	void apply(int node,int ss,int se,ll x){ //apply x to tree[i]
		if(x==LLONG_MIN)
			return;
		ll len=se-ss+1;
		tree[node].sum=len*x;
		tree[node].lazy=x;
	}
	void push(int node,int ss,int se){ // make lazy[i]=0 i.e push its changes to children
		if(ss!=se){
			int m=(ss+se)/2;
			ll x=tree[node].lazy;
			apply(2*node,ss,m,x);
			apply(2*node+1,m+1,se,x);
		}
		tree[node].lazy=LLONG_MIN;
	}
	void update(int node,int ss,int se,int qs,int qe,ll x){ //add x to [qs,qe] range
		if(qe<ss or qs>se)
			return;
		if(qs<=ss and qe>=se){
			apply(node,ss,se,x);
			return;
		}
		push(node,ss,se); // push changes to children before going to them
		int m=(ss+se)/2,lc=2*node,rc=2*node+1;
		update(lc,ss,m,qs,qe,x);
		update(rc,m+1,se,qs,qe,x);
		tree[node].sum=tree[lc].sum+tree[rc].sum;
	}
	ll query(int node,int ss,int se,int qs,int qe){ //get sum of x PS: WHEN at node i we have correct/updated sum of range [qs,qe]
		if(qe<ss or qs>se)
			return 0;
		if(qs<=ss and qe>=se)
			return tree[node].sum;
		push(node,ss,se); // push changes to children before going to them
		int m=(ss+se)/2,lc=2*node,rc=2*node+1;
		return query(lc,ss,m,qs,qe)+query(rc,m+1,se,qs,qe);
	}
	void update(int qs,int qe,int x){
		return update(1,0,n-1,qs,qe,x);
	}
	ll query(int qs,int qe){
		return query(1,0,n-1,qs,qe);
	}
};