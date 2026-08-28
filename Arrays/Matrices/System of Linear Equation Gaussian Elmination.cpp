/*
 augment matrix has the soln of each linear eqaution at the end
 [[a1,a2,...am|bm]
 ....
 ]
 i.e a1x1+a2x2+...+amxm=bm
 */
pair<int,vector<int>> solve_system_of_linear_equation_mod(matrix &augment_mat){
  matrix mat=augment_mat;
  int n=mat.size(),m=mat[0].size();
  int vars=m-1;
  vector<int> where(vars,-1); //in which row each variable ans is
  int row=0;// the row from below we can search for non-1 element
  for(int col=0;col<vars and row<n;col++){;// last column is const
    int i=row;
    for(;i<n;i++){
      if(mat[i][col]!=0)
        break;
    }
    if(i==n)// all are 0 below it this column cant have 1
      continue;
    swap(mat[row],mat[i]);
    // make [row][col] 1
    ll inv=mod_inv_fermat(mat[row][col],mod);
    for(int j=col;j<m;j++)
      mat[row][j]=(inv*mat[row][j])%mod;
    // make all cells in this col except mat[row][col] as 0
    for(int i=0;i<n;i++){ 
      if(i==row)
        continue;
      ll k=mat[i][col];
      for(int j=col;j<m;j++){
        mat[i][j]=(mat[i][j]-mat[row][j]*k)%mod;
        if(mat[i][j]<0)
          mat[i][j]+=mod;
      }
    }
    where[col]=row;
    row++;// this row has a leading 1 now
  }
  for(int i=0;i<n;i++){
    bool all_zero=true;
    for(int j=0;j<m-1;j++){
      if(mat[i][j]!=0){
        all_zero=false;
        break;
      }
    }
    if(all_zero and mat[i][m-1]!=0)// Inconsistent system 0!=(non-0)
      return {0,{}};
  }

  int rank=row; // number of rows with leading-1
  vector<int> ans(vars,0);
  for(int i=0;i<vars;i++){
    if(where[i]!=-1)
      ans[i]=mat[where[i]][m-1];
  }
  if(rank==m-1){//1 Soln
    return {1,ans};
  }else{//Infinite Soln
    return {2,ans};
  }
}