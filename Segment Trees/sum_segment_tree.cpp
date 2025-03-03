struct Sum_seg_tree{
	vector<ll> seg_tree;
	int sz;
	Sum_seg_tree(int n){
		sz=n;
		seg_tree.resize(4*n);
	}
	void update_internal(int idx,int val,int si,int ss,int se){
		if(ss==se){
			seg_tree[si]=val;
			return;
		}
		int mid=ss+(se-ss)/2,lc=2*si+1,rc=2*si+2;
		if(idx<=mid){
			update_internal(idx,val,lc,ss,mid);
		}else{
			update_internal(idx,val,rc,mid+1,se);
		}
		seg_tree[si]=seg_tree[lc]+seg_tree[rc];
	}
	void update(int idx,int val){
		update_internal(idx,val,0,0,sz-1);
	}
	ll get_sum_internal(int qs,int qe,int si,int ss,int se){
		if(qs<=ss and qe>=se)
			return seg_tree[si];
		if(qs>se or qe<ss)
			return 0;
		int mid=ss+(se-ss)/2,lc=2*si+1,rc=2*si+2;
		return get_sum_internal(qs,qe,lc,ss,mid)+get_sum_internal(qs,qe,rc,mid+1,se);
	}
	ll get_sum(int qs,int qe){
		return get_sum_internal(qs,qe,0,0,sz-1);
	}
};