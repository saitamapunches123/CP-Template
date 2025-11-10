/*
The time complextity of dp in recurson is often misunderstood a lot of times. We think of it as O(number of states)
wheres the correct time complexity is O(number of states * time taken to transition from one state to another)

For example:
*/
ll recur(int i,int k,vector<int> &nums){
    if(i>=n or k==0)
        return 0;
    if(dp[i][k]!=-1)
        return dp[i][k];
    int mx=0,mn=INT_MAX;
    ll ans=0;
    for(int j=i;j<n;j++){
        mx=max(mx,nums[j]);
        mn=min(mn,nums[j]);
        ans=max(ans,recur(j+1,k-1,nums)+mx-mn);
    }
    return dp[i][k]=ans;
}

//TC here is n^3 n^2 states and n time to transition from one state to another
// so if we want to simplify it we can either use tabulation or change the state definetions

//1) Changing state definetions
// now number of states are 3*n^2 and time to transition from one state to another is 1
ll recur(int i,int k,int state,vector<int> &nums){
    if(k==0)
        return 0;
    if(i==n)
        return state==0?0:-inf;
    if(dp[i][k][state]!=-1)
        return dp[i][k][state];
    ll ans=recur(i+1,k,state,nums),cans=0;
    if(state==0){// i can be max or min
        cans=recur(i+1,k-1,1,nums)-nums[i];// picking nums[i] as min
        ans=max(ans,cans);
        cans=recur(i+1,k-1,2,nums)+nums[i];// picking nums[i] as max
        ans=max(ans,cans);
    }else{
        if(state==1){//picking it as max
            cans=recur(i+1,k-1,0,nums)+nums[i];
            ans=max(ans,cans);
        }else{//picking it as min
            cans=recur(i+1,k-1,0,nums)-nums[i];
            ans=max(ans,cans);
        }
    }
    return dp[i][k][state]=ans;
}
/*
2) Tabulation

Tabulation offers 2 advantages
1) It doesnt have recursion overhead thus if the TC is fine. but still giving TLE in dp+recursion then try tabulation, If still giving TLE then try tabulation+space optimization (THIS WILL BE THE MOST OPTIMAL SOLUTION AND SHOUDL PASS)

2) In a lot of cases we can reducse the transition time from one state to another using tabulation:

For example:
if dp[i][j]=max(dp[i+1][0],dp[i+1][1],dp[i+1][2]....dp[i+1][j-1])) using memization will take n transtiton time
but in tabulation we can do it in 1 transition time by keeping a prefix max array


What will solve the problem?

Depends on the use case if your theoretical TC is over the limit (doing aroung 1e9 instructions) then tabulation wont help
but if your theoretical TC is under the limit(doing <=1e8 instruction) then tabulation will help remove TLE.
*/
