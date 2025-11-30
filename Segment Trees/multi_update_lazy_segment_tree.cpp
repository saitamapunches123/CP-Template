/* add multi update range tree
1) add x in l,r
2) set x in l,r
3) get sum of l,r
*/

//PS: this type of segmentree only works when the different updates can be clubed together
enum QueryType { ADD, SET };
// same as creatiing tow integer 0-> add and 1->set just a better coding practice

struct Query{
  QueryType type;// 0 ->add 1->set
  ll val=0;
  Query(QueryType t,ll x){
    type=t;
    val=x;
  }
};
struct LazyMultiSegTree{
  int n;
  vector<ll> st;//st[node] -> sum of nodes in the range only
  vector<Query> lazy;//lazy[node] what kind of operation is to be doing in range on node
  LazyMultiSegTree(int sz){
    n=sz;
    st.assign(4*n,0ll);
    lazy.assign(4*n,Query{ADD,0});
  }
  void apply(int node,int ss,int se,Query &x){
    ll len=se-ss+1;
    if(x.type==ADD){
        st[node]+=len*x.val;
        lazy[node].val+=x.val; //ADD on SET or ADD on ADD just ADD it
     }
    else{ //x.type is SET
        st[node]=len*x.val;
        lazy[node]=x; // SET on SET or SET on SET overwrites it
    }
  }
  void push(int node,int ss,int se){
    if(ss!=se){
      int m=(ss+se)/2;
      apply(2*node,ss,m,lazy[node]);
      apply(2*node+1,m+1,se,lazy[node]);
    }
    lazy[node]=Query{ADD,0};
  }
  void update(int node,int ss,int se,int qs,int qe,Query &x){
    if(qs>se or qe<ss)
        return;
    if(qs<=ss and qe>=se){
      apply(node,ss,se,x);
      return;
    }
    push(node,ss,se);
    int lc=2*node,rc=2*node+1,mid=(ss+se)/2;
    update(lc,ss,mid,qs,qe,x);
    update(rc,mid+1,se,qs,qe,x);	  
    st[node]=st[lc]+st[rc];
  }
  // can use update(i,i,x) to update 1 value during build()
  void update(int qs,int qe,Query x){
    update(1,0,n-1,qs,qe,x);
  }
  ll query(int node,int ss,int se,int qs,int qe){
    if(qs>se or qe<ss)
        return 0ll;
    if(qs<=ss and qe>=se)
      return st[node];
    push(node,ss,se);
    int lc=2*node,rc=2*node+1,mid=(ss+se)/2;
    return query(lc,ss,mid,qs,qe)+query(rc,mid+1,se,qs,qe);
  }
  // can use query(i,i,x) to query for 1 value
  ll query(int qs,int qe){
    return query(1,0,n-1,qs,qe);
  }
};