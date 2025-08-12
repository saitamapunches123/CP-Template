/* add multi update range tree
1) add x in l,r
2) set x in l,r
3) get sum of l,r
*/

//PS: this type of segmentree only works when the different updates can be clubed together
enum QueryType { ADD, SET };
// same as creatiing tow integer 0-> add and 1->set just a better coding practice

struct Query{
  QueryType type;
  ll val=0;
  Query(QueryType t,ll x){
    type=t;
    val=x;
  }
};
struct LazyMultiSegTree{
  int n;
  vector<ll> st;//st[node] -> sum of nodes in the range only
  vector<Query> lazy;//lazy[node] -> what kind of operation is to be doing in range on node
  LazyMultiSegTree(int sz){
    n=sz;
    st.assign(4*n,0ll);
    lazy.assign(4*n,Query{ADD,0});
  }
  void push(int node,ll ss,ll se){
    ll val=lazy[node].val,len=se-ss+1;
    if(lazy[node].type==SET)
      st[node]=val*len;
    else
      st[node]+=val*len;
    if(ss!=se){
      apply(lazy[node],lazy[2*node]);
      apply(lazy[node],lazy[2*node+1]);
    }
    lazy[node]=Query{ADD,0};
  }
  // apply q1 to q2
  void apply(Query &q1,Query &q2){
    if(q1.type==SET){
      q2=q1;
      return;
    }
    // if applting add to either set or add
    q2.val+=q1.val;
  }
  void update(int node,int ss,int se,Query &x,int qs,int qe){
	  push(node,ss,se);
	  if(qs<=ss and qe>=se){
	    apply(x,lazy[node]);
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
	void update(int qs,int qe,Query x){
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
	// can use query(i,i,x) to query for 1 value
	ll query(int qs,int qe){
		return query(1,0,n-1,qs,qe);
	}
};