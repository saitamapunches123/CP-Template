/*
Picking a subsequence is a common dp problem
FOR EXAMPLE: LIS,LCS,LCIS,https://www.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1 etc
here dp states can be defined in 2 ways
1) dp[i]=length of longest subsequence ending at i
2) dp[i]=length of longest subsequence given that i is the last element of the subsequence(compulsoary i is getting picked)

The second way is better for subsequence pattern
*/

//FOR EXAMPLE:
int maxSumIS(vector<int>& arr) {
    int n=arr.size(),ans=0;
    vector<int> dp(n);
    for(int i=0;i<n;i++){
        dp[i]=arr[i];
        for(int j=0;j<i;j++){
            if(arr[j]<arr[i])
                dp[i]=max(dp[i],dp[j]+arr[i]);
        }
        ans=max(ans,dp[i]);
    }
    return ans;
}
// but here using a recursive solution would lead to 2 variables (index,last picked element) but the above solutiong is simpler