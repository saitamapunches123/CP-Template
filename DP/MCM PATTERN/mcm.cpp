/*
MCM matrix chain multiplication pattern in helpful for questions where the order of operations decide the final answer,
and we need to minimize/maximize or count the number of ways to get the answer

TRANSITIONS:
k from i to j-1
doing k th operator first
dp[i][j] = dp[i][k] + dp[k+1][j] + val;
// The value of expression from i-th to j-th depends on the partition at k,
// where val represents the cost of merging the results of the two partitions. i to k and k+1 to j

WHY IT WORKS?
lets say 
(m1(m2m3))m4

*/

//FOR EXAMPLE:
 int recur(vector<int> &a,int l,int r){
    if(r==l+2){
        return a[l]*a[l+1]*a[l+2];
    }
    if(r==l+1)
    return 0;
    if(dp[l][r]!=-1)
    return dp[l][r];
    int ans=INT_MAX;
    for(int m=l+1;m<r;m++){
        int cans=recur(a,l,m)+recur(a,m,r)+a[l]*a[m]*a[r];
        ans=min(ans,cans);
    }
    return dp[l][r]=ans;
}
//TC: n^3 (n^2 states and each state has n transitions)
//SC: n^2
