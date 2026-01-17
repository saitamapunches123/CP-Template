struct Generic_seg_tree{
	vector<ll> seg_tree;
	ll n,base_value=LLONG_MAX; //change this
	ll merge(ll val1,ll val2){
		return min(val1,val2); //change this based on Min,Max,Sum segment tree
	}
	Generic_seg_tree(int sz){
		n=sz;
		seg_tree.assign(4*n,base_value);
	}
	void update(int idx,int val,int si,int ss,int se){
		if(ss==se){
			seg_tree[si]=val; //change this based on the problem if you need to set the value than use seg_tree[si]=val
			return;
		}
		int mid=ss+(se-ss)/2,lc=2*si+1,rc=2*si+2;
		if(idx<=mid){
			update(idx,val,lc,ss,mid);
		}else{
			update(idx,val,rc,mid+1,se);
		}
		seg_tree[si]=merge(seg_tree[lc],seg_tree[rc]);
	}
	void update(int idx,int val){
		update(idx,val,0,0,n-1);
	}
	ll query(int qs,int qe,int si,int ss,int se){
		if(qs<=ss and qe>=se)
			return seg_tree[si];
		if(qs>se or qe<ss)
			return base_value;
		int mid=ss+(se-ss)/2,lc=2*si+1,rc=2*si+2;
		return merge(query(qs,qe,lc,ss,mid),query(qs,qe,rc,mid+1,se));
	}
	ll query(int qs,int qe){
		if(qs>qe)
			return base_value;
		return query(qs,qe,0,0,n-1);
	}
};