/*
 Dnc Dp is the pattern when dp[i] = min(dp[j] + cost(j, i)) 
                            for all j < i
it can also be in the layered form i.e (break the array into k subarrays and find the min cost)
dp[i][k] = min(dp[j][k-1] + cost(j, i))  cost(j, i) ->cost of subarray (j,i)
          for all j < i


NAIVE Implementation: O(n^2) -> as for each state we are iterating over all previous states

OPTIMIZATION:
1) If cost function follows the quadrilateral inequality then we can use opt(i)<=opt(i+1) 
2) 
*/
void recur(int l,int r,int optl,int optr){ // optl,optr the range in which opt can be
  if(l>r) return;
  int mid=(l+r)/2;
  dp[mid]=inf;
  for(int j=optl;j<=min(mid-1,optr);j++){
    if(dp[mid]>dp[j]+cost(j,mid)){
      dp[mid]=dp[j]+cost(j,mid);
      opt[mid]=j;
    }
  }
  recur(l,mid-1,optl,opt[mid]);
  recur(mid+1,r,opt[mid],optr); 
}

// TC: nlogn as at each level we do n work no optl,optr at a level overlaps and logn levels


// TC for layered DP :n*k*logn (k layers)

/*
For layered DP: opt(i,g)<=opt(i+1,g) i.e monotnicity holds for each layer
but as 
  dp[i][g]=min(dp[j][g-1]+cost(j,i)) for j<i

we can implement this as first calculate all dp[i][1] than all dp[i][2] and so on....

thus on calculating dp[i][g] all dp[i][g-1] is already calculated
*/

void recur(int l,int r,int g,int optl,int optr,prefix_sum_2D &obj){
  if(l>r)
    return;
  int mid=(l+r)/2,opt=optl;
  dp[mid][g]=inf;
  for(int k=optl;k<=min(optr,mid-1);k++){
    ll cans=dp[k][g-1]+obj.get_sub_matix_sum(k+1,k+1,mid,mid); // to optimize can use space optimized DP
    if(cans<dp[mid][g]){
      dp[mid][g]=cans;
      opt=k;
    }
  }
  recur(l,mid-1,g,optl,opt,obj);
  recur(mid+1,r,g,opt,optr,obj);
}

//COMPUTE FOR ALL LAYERS
for(int g=2;g<=k;g++)
  recur(1,n,g,1,n,obj);

https://codeforces.com/problemset/problem/868/F