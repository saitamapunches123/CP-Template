/*
Sparse Segement Tree also called Dynamic Segment Tree is usefull when the range of queries is large(>1e6).
Thus making node for each index is not feasible. So we make node only when needed like Tries.

Now for each query we traverse logn elements so TC is logn per query.
*/

//PS: a lot of sparse segment tree question can be solved with segmentree + cordianate compression







/* 
  Sparse Lazy sum tree
  1) range Add (add x to [qs,qe])
  2) range sum
*/
int max_n=1e9+10;
struct Sparse_Seg_Tree{
  struct Node{
    ll sum=0,lazy=0;
    Node *left=NULL,*right=NULL;
  };
  Node* root=new Node();	
  void apply(Node* node,int ss,int se,int x){
    ll len=se-ss+1;
    node->sum+=len*x;
    node->lazy+=x;
  }
  void push(Node* node,int ss,int se){
    if(ss!=se){
      int m=ss+(se-ss)/2;
      if(node->left==NULL)
        node->left=new Node();
      if(node->right==NULL)
        node->right=new Node();
      apply(node->left,ss,m,node->lazy);
      apply(node->right,m+1,se,node->lazy);
    }
    node->lazy=0;
  }
  void update(Node* node,int ss,int se,int qs,int qe,int x){// pointers are passed by reference
    if(qe<ss or qs>se)
      return;
    if(qs<=ss and qe>=se){
      apply(node,ss,se,x);
      return;
    }
    push(node,ss,se);
    int m=ss+(se-ss)/2;
    update(node->left,ss,m,qs,qe,x);
    update(node->right,m+1,se,qs,qe,x);
    node->sum=node->left->sum+node->right->sum;
  }
  ll query(Node *node,int ss,int se,int qs,int qe){
    if(qe<ss or qs>se)
      return 0ll;
    if(qs<=ss and qe>=se){
      return node->sum;
    }
    push(node,ss,se);
    int m=ss+(se-ss)/2;
    return query(node->left,ss,m,qs,qe)+query(node->right,m+1,se,qs,qe);
  }
  ll query(int qs,int qe){
    return query(root,0,max_n,qs,qe);
  }
  void update(int qs,int qe,int x){
    update(root,0,max_n,qs,qe,x);
  }
};

/* 
  Sparse Lazy sum tree
  1) range set (set [qs,qe] to x)
  2) range sum
*/
int max_n=1e9+10;
struct Sparse_Seg_Tree{
  struct Node{
    ll sum=0,lazy=LLONG_MIN;// using LLONG_MIN as Sentinal value
    Node *left=NULL,*right=NULL;
  };
  Node* root=new Node();	
  void apply(Node* node,int ss,int se,int x){
    if(x==LLONG_MIN)
      return;
    ll len=se-ss+1;
    node->sum=len*x;
    node->lazy=x;
  }
  void push(Node* node,int ss,int se){
    if(ss!=se){
      int m=ss+(se-ss)/2;
      if(node->left==NULL)
        node->left=new Node();
      if(node->right==NULL)
        node->right=new Node();
      apply(node->left,ss,m,node->lazy);
      apply(node->right,m+1,se,node->lazy);
    }
    node->lazy=LLONG_MIN;
  }
  void update(Node* node,int ss,int se,int qs,int qe,int x){// pointers are passed by reference
    if(qe<ss or qs>se)
      return;
    if(qs<=ss and qe>=se){
      apply(node,ss,se,x);
      return;
    }
    push(node,ss,se);
    int m=ss+(se-ss)/2;
    update(node->left,ss,m,qs,qe,x);
    update(node->right,m+1,se,qs,qe,x);
    node->sum=node->left->sum+node->right->sum;
  }
  ll query(Node *node,int ss,int se,int qs,int qe){
    if(qe<ss or qs>se)
      return 0ll;
    if(qs<=ss and qe>=se){
      return node->sum;
    }
    push(node,ss,se);
    int m=ss+(se-ss)/2;
    return query(node->left,ss,m,qs,qe)+query(node->right,m+1,se,qs,qe);
  }
  ll query(int qs,int qe){
    return query(root,0,max_n,qs,qe);
  }
  void update(int qs,int qe,int x){
    update(root,0,max_n,qs,qe,x);
  }
};
