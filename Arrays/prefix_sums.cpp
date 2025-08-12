// using 1 based indexing on prefix sum ps[i]= sum of all elements with index<i

//2d prefix sum to get sum of a sub matrix
struct prefix_sum_2D{
      vector<vector<ll>> ps;// let ps[r][c] be the sum of matrix right and above r,c i.e i<r and j<c
      prefix_sum_2D(vector<vector<int>> &mat){
          int n=mat.size(),m=mat[0].size();
          ps.assign(n+1,vector<ll>(m+1,0ll));
          // ps[i][j]= row sum[j]+ps[i-1][j]
          for(int i=1;i<=n;i++){
              ll row_sum=0;
              for(int j=1;j<=m;j++){
                  row_sum+=mat[i-1][j-1];
                  ps[i][j]=row_sum+ps[i-1][j];
              }
          }
      }
      //using inclusoion exclusion principle assuming r2>r1 and c2>c1
      ll get_sub_matix_sum(int r1,int c1,int r2,int c2){
          ll sum=ps[r2+1][c2+1]-ps[r1][c2+1]-ps[r2+1][c1]+ps[r1][c1]; // as removed twice so added once
          return sum;
      }
    };

//  1d prefix sum to get sum of a sub array
struct prefix_sum_1D {
    vector<int> ps;//using the definition ps[i]= sum of all elements with index<i
    prefix_sum_1D(vector<int>& arr) {
        int n=arr.size();
        ps.assign(n+1,0ll);
        for(int i=1;i<=n;i++)
            ps[i]=ps[i-1]+arr[i-1];
    }
    ll sumRange(int l, int r) {
        return ps[r+1]-ps[l];
    }
};