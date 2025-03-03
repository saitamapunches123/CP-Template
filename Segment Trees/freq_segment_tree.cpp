//To get frequency of the elemets in the range
//NOTE ONLY USE THIS IF THE NUMBER OF VALUE IS VERY LESS


struct CntSegTree{
    vector<vector<int>> seg_tree;
    int sz,max_val;
    CntSegTree(int n,int mv){ //mv maxnimum value the array can have only usefull if this iv ery less
      sz=n;
      max_val=mv;
      seg_tree.assign(4*sz,vector<int>(max_val+1));
    }
    // to update a[idx]=val
    void update(int idx,int val,int i=0,int ss=0,int se=-1){
      if(se==-1)
      se=sz-1;
      if(ss==se){
        for(auto &x:seg_tree[i])
        x=0;
        seg_tree[i][val]++;
        return;
      }
      int mid=(ss+se)/2;
      int lc=2*i+1,rc=2*i+2;
      if(idx<=mid){
        update(idx,val,lc,ss,mid);
      }else{
        update(idx,val,rc,mid+1,se);
      }
      for(int val=0;val<=max_val;val++)
      seg_tree[i][val]=seg_tree[lc][val]+seg_tree[rc][val];
    }
    void display_top(){
      for(auto x:seg_tree[0])
      cout<<x<<" ";
      cout<<endl;
    }
    vector<int> get_cnt(int l,int r,int i=0,int ss=0,int se=-1){
      if(se==-1)
      se=sz-1;
      if(l<=ss and r>=se){
        return seg_tree[i];
      }
      vector<int> ans(max_val+1,0);
      if(l>se or r<ss)
      return ans;
      int mid=(ss+se)/2;
      int lc=2*i+1,rc=2*i+2;
      vector<int> left=get_cnt(l,r,lc,ss,mid);
      vector<int> right=get_cnt(l,r,rc,mid+1,se);
      for(int val=0;val<=max_val;val++)
      ans[val]=left[val]+right[val];
      return ans;
    }  
};