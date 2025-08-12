/* 
	lazy sum tree
	1) range update
	2) range sum
*/
struct LazySumSegTree{
  int n;
  vector<ll> st,lazy;
  LazySumSegTree(int sz){
    n=sz;
    st.assign(4*n,0ll);
    lazy.assign(4*n,0ll);
  }
  //always push before reading or writing
  void push(int node,ll ss,ll se){
    st[node]+=lazy[node]*(se-ss+1);
    if(ss!=se){
      lazy[2*node]+=lazy[node];
      lazy[2*node+1]+=lazy[node];
    }
    lazy[node]=0;
  }
  void update(int node,int ss,int se,int x,int qs,int qe){
	  push(node,ss,se);
	  if(qs<=ss and qe>=se){
	    lazy[node]+=x;
	    push(node,ss,se);
	    return;
	  }
	  if(ss>qe or se<qs)
	    return;
	  int lc=2*node,rc=2*node+1,mid=(ss+se)/2;
	  update(lc,ss,mid,x,qs,qe);
	  update(rc,mid+1,se,x,qs,qe);
	  push(lc,ss,mid);
	  push(rc,mid+1,se);
	  st[node]=st[lc]+st[rc];
	}
	// can use update(i,i,x) to update 1 value during build()
	void update(int qs,int qe,int x){
		update(1,0,n-1,x,qs,qe);
	}
	ll query(int node,int ss,int se,int qs,int qe){
	  push(node,ss,se);
		if(qs<=ss and qe>=se){
			return st[node];
		}
		if(ss>qe or se<qs)
	    return 0ll;
	  int lc=2*node,rc=2*node+1,mid=(ss+se)/2;
	  return query(lc,ss,mid,qs,qe)+query(rc,mid+1,se,qs,qe);
	}
	ll query(int qs,int qe){
		return query(1,0,n-1,qs,qe);
	}
};