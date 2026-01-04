// https://leetcode.com/problems/knight-probability-in-chessboard/description/

double dp[30][30][120]; // dp[r][c][k]-> probablity of knight staying on board starting from r,c,k state
double recur(int r,int c,int k){
    if(r<0 or c<0 or r>=n or c>=n)
        return 0;// knight moved out of board
    if(k==0)
        return 1; //no more moves left knight on board
    if(dp[r][c][k]!=-1)
        return dp[r][c][k];
    double ans=0;
    for(auto [dr,dc]:deltas){
        int nr=r+dr,nc=c+dc;
        ans+=recur(nr,nc,k-1)/8; // as here each transtion equally likely
    }
    return dp[r][c][k]=ans;
}

//PS: IN MOST QUESTION DOUBLE WILL LEAD TO ERROR SO USE pair<int,int> to represent fractions