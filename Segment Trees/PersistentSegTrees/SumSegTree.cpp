/*
  Persistent seg tree can be usefull when dealing with ranges or 2d arrays
  as dor dealing with ranges [l,r] we can make l as time and r as index 
*/

struct PersistentSumSegTree{
  struct Node{
    ll val=0;
    Node *left=NULL,*right=NULL;
    Node(ll x): val(x) {}
    Node(ll x,Node *l,Node *r): val(x), left(l), right(r) {}
  };
  ll merge(ll l,ll r){
    return l+r;// change here to make it max/min etc..
  }
  Node* merge(Node *left,Node *right){
    ll val=merge(left->val,right->val);
    return new Node(val,left,right);
  }
  vector<Node*>roots;
  int n;
  PersistentSumSegTree(vector<int> &a,int q){
    roots.assign(q,NULL);// q-> max time or number of queries
    n=a.size();
    roots[0]=build(a,0,n-1);
  }
  Node* build(vector<int> &a,int l,int r){
    if(l==r)
      return new Node(a[l]);
    int mid=(l+r)/2;
    return merge(build(a,l,mid),build(a,mid+1,r));
  }
  // at each level only creating 1 new node so log n old 
  Node *update(Node *root,int l,int r,int i,int x){
    if(l==r)
      return new Node(x);
    int mid=(l+r)/2;
    if(i<=mid)
      return merge(update(root->left,l,mid,i,x),root->right);
    else
      return merge(root->left,update(root->right,mid+1,r,i,x));
  }
  void update(int time,int i,int x){// update the roots[time][i] to x
    roots[time]=update(roots[time],0,n-1,i,x);
  }
  void clone(int prev_time,int curr_time){// create a clone of prev_time in curr_time PS:if we update prev_time curr_time wont get impacted as  prev_time update will create new nodes
    roots[curr_time]=roots[prev_time];
  }
  ll query(Node *root,int l,int r,int qs,int qe){
    if(qs>r or qe<l)
      return 0; // here for sum change for max min etc..
    if(qs<=l and qe>=r)
      return root->val;
    int mid=(l+r)/2;
    ll ans=merge(query(root->left,l,mid,qs,qe),query(root->right,mid+1,r,qs,qe));
    return ans;
  }
  ll query(int time,int qs,int qe){// query on time/version=t from l to r
    return query(roots[time],0,n-1,qs,qe);
  }
};