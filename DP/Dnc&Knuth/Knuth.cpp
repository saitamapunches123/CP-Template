/*
Knuth opts is usefull for Interval DP or MCM pattern

where dp[i][j]=min(dp[i][k]+dp[k+1][j])+cost[i][j]
               for k in i to j-1
Naive TC: n^3

Knuth Opts TC: n^2
as if the cost function statisfies Quadrangele Inequality:
opts[i][j-1]<=opts[i][j]<=opts[i+1][j]

HOW TO ITERATE?
as we need result of opts[i][j-1] and opts[i+1][j] for (i,j) 
PS: length of (i,j-1) and (i+1,j) is j-i and for (i,j) is j-i+1

THUS WE CAN ITERATE IN INCREASING LENGTH:
get answer for length 1(base case) than lenght 2 and so on....
*/

void recur(int i,int j,vector<int> &pref){
    int cost=pref[j];
    if(i-1>=0)
        cost-=pref[i-1];
    if(j==i){ //base case
        dp[i][j]=cost;
        opts[i][j]=i;
        return;
    }
    int s=i,e=j;
    if(j-1>=0)
        s=max(s,opts[i][j-1]);
    if(i+1<n)
        e=min(e,opts[i+1][j]);
    dp[i][j]=inf;
    for(int k=s;k<=e;k++){
        int cans=0;
        if(k-1>=i) //change breaking logic and cist based on problem
            cans=dp[i][k-1];
        if(k+1<=j)
            cans+=dp[k+1][j];
        if(cans<dp[i][j]){
            dp[i][j]=cans;
            opts[i][j]=k;
        }
    }
    dp[i][j]+=cost;
}

for(int len=1;len<=n;len++){
    for(int i=0;i<=n-len;i++){
        int j=i+len-1;
        recur(i,j,pref);
    }
}

https://www.geeksforgeeks.org/problems/optimal-binary-search-tree2214/1