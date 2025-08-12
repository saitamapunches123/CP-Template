/*
usefull for questions that has static queries i.e 
first process q queries of type
1 l r x -> add x to a[l...r]
and than after processing all queries return final array a


step1) create diff array
than for each query
    diff[l]+=x diff[r+1]-=x
step2) 
    update the arr arr[i] =arr[i]+pref_sum_diff[i]
*/

//  for 1d
int n=arr.size();
vector<ll> diff(n+1);
for(auto &q:queries){
    int l=q[0],r=q[1],x=q[2];
    diff[l]+=x;
    diff[r+1]-=x;
}
ll sum=0;
for(int i=0;i<n;i++){
    sum+=diff[i];
    arr[i]+=sum;
}

// for 2d 
struct prefix_sum_2D{
    vector<vector<ll>> ps;// let ps[r][c] be the sum of matrix right and above r,c i.e i<r and j<c
    prefix_sum_2D(vector<vector<ll>> &mat){
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
int n=mat.size(),m=mat[0].size();
vector<vector<ll>>diff(n+1,vector<ll>(m+1));
for(auto &q:queries){
    int x=q[0],r1=q[1],c1=q[2],r2=q[3],c2=q[4]; //add x to sub matrix from r1,c1 to r2,c2
    diff[r1][c1]+=x;
    diff[r1][c2+1]-=x;
    diff[r2+1][c1]-=x;
    diff[r2+1][c2+1]+=x;//using inclusion-exclusion princple subtracted twice
}
prefix_sum_2D obj(diff);
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        mat[i][j]+=obj.get_sub_matix_sum(0,0,i,j);
    }
}