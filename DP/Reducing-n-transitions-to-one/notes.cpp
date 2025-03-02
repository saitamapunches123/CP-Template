/*
Lets say we need two dimension dp[i][j] to represent each state (sub-problem).
But each state can have n transitions.
lets say 
we are picking sub arrays i.e
dp[i][j]=> i is current index and j is the count of the number of subarrays picked from the i values

So,
dp[i][j]=max(dp[i-1][j]                    // not picking any sub array ending at ith element
            dp[i-1][j-1]+a[i]             // picking a[i] as subarray
            dp[i-2][j-2]+a[i-1]+a[i-2]   // picking a[i-1...i] as sub array
            ans so on...
            )

Thus for solving  each state we need to do n work so tc=n^3

HOW TO SOLVE IT IN n^2
we can reduce the n transitions to only 1
by keeping track of only the best_score and only picking that


where score for any index k will be dp[k][j-1]-ps[k-1]
as dp[i][j]=dp[k][j-1]+ps[i]-ps[k-1] max over all k
so dp[i][j]=max(dp[i-1][j],
                best_score+ps[i]
                )
*/

vector<vector<int>>dp(n+1,vector<int>(k+1,INT_MIN));

for(int i=0;i<=n;i++)
    dp[i][0]=0;

for(int j=1;j<=k;j++){ // NOTE: have to solve it j wise as we need best_score for j-1 to solve for j
    int best_score=INT_MIN,min_idx=j;
    for(int i=min_idx;i<=n;i++){
        int curr_score=dp[i-m][j-1];
        if(i>0)
        curr_score-=ps[i-1];
        best_score=max(best_score,curr_score); //keeping a prefix max of best_core
        dp[i][j]=max(dp[i-1][j],best_score+ps[i-1]);
    }
}