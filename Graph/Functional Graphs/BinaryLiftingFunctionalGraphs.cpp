//PS: In a lot of questions costs is not required we just need to find the node after k moves

struct BinaryLiftingFunctionalGraphs{
  int n,log_sz;
  vector<vector<int>> up; // up[i][j]=> starting from node i where will we be after doing 2^k ops
  vector<vector<ll>> costs;
  ll merge_cost(ll c1,ll c2){
    return c1+c2;//change cost based on question
  }
  BinaryLiftingFunctionalGraphs(vector<int> &a){
    n=a.size();
    log_sz=31; //change based on question
    up.assign(n,vector<int>(log_sz));
    costs.assign(n,vector<ll>(log_sz));//use if required
    for(int j=0;j<log_sz;j++){
      for(int i=0;i<n;i++){
        if(j==0){
          up[i][j]=a[i];//2^0=1
          costs[i][j]=i;//change cost based on question
        }
        else{
          int m=up[i][j-1];
          up[i][j]=up[m][j-1];//2^j-1+2^j-1=2^j
          costs[i][j]=merge_cost(costs[i][j-1],costs[m][j-1]);
        }
      }
    }
  }
  pair<int,ll> query(int u,int t){//starting from b moving t times where will you be and how much will it cost
    int ans=u;
    ll cost=0;
    for(int b=0;b<log_sz;b++){
      int rep=1<<b;
      if(rep&t){
        cost=merge_cost(cost,costs[ans][b]);
        ans=up[ans][b];
      }
    }
    return {ans,cost};
  }
};