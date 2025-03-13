
/*
If you have to process queries of 
l r x add x to all a[l] to a[r]
idx get value of a[idx] can use lazy sum segment tree does both in log n time.
*/


struct LazySumSegTree
{
	vector<ll> seg_tree;
	int n;
	LazySumSegTree(int sz){
		n=sz;
		seg_tree.assign(4*n,0);
	}

	void update_segment(int qs,int qe,int ss,int se,int idx,int x){
		if(qs<=ss and qe>=se){
			seg_tree[idx]+=x;
			return;
		}
		if(qs>se or qe<ss)
			return;
		int m=ss+(se-ss)/2,lc=2*idx+1,rc=2*idx+2;
		update_segment(qs,qe,ss,m,lc,x);
		update_segment(qs,qe,m+1,se,rc,x);
	}

	void update(int qs,int qe,int x){
		update_segment(qs,qe,0,n-1,0,x);
	}

	ll get_val_helper(int req_idx,int ss,int se,int idx){
		if(ss==se){
			return seg_tree[idx];
		}
		int m=ss+(se-ss)/2,lc=2*idx+1,rc=2*idx+2;
		if(req_idx<=m)
			return seg_tree[idx]+get_val_helper(req_idx,ss,m,lc);
		else
			return seg_tree[idx]+get_val_helper(req_idx,m+1,se,rc);//just give the running sum of all the values
	}
	ll get_val(int req_idx){
		return get_val_helper(req_idx,0,n-1,0);
	}
	
};