struct Sum_seg_tree{
	vector<ll> seg_tree;
	int sz;
	Sum_seg_tree(int n){
		sz=n;
		seg_tree.resize(4*n);
	}
	void update(int idx,int val,int si,int ss,int se){
		if(ss==se){
			seg_tree[si]+=val; //change this based on the problem if you need to set the value than use seg_tree[si]=val
			return;
		}
		int mid=ss+(se-ss)/2,lc=2*si+1,rc=2*si+2;
		if(idx<=mid){
			update(idx,val,lc,ss,mid);
		}else{
			update(idx,val,rc,mid+1,se);
		}
		seg_tree[si]=seg_tree[lc]+seg_tree[rc];
	}
	void update(int idx,int val){
		update(idx,val,0,0,sz-1);
	}
	ll query(int qs,int qe,int si,int ss,int se){
		if(qs<=ss and qe>=se)
			return seg_tree[si];
		if(qs>se or qe<ss)
			return 0;
		int mid=ss+(se-ss)/2,lc=2*si+1,rc=2*si+2;
		return query(qs,qe,lc,ss,mid)+query(qs,qe,rc,mid+1,se);
	}
	ll query(int qs,int qe){
		if(qs>qe)
				return 0;
		return query(qs,qe,0,0,sz-1);
	}
};