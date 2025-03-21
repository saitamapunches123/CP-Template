/*
Re-routing can be helpful if you want to get answer for node[i] considering node[i] as root of tree


HOW IT WORKS?
we combine the answer for node in sub tree of node (dp1) 
with the answer for node outisde the sub tree of node (dp2)

NOTE: WE NEED TO DO 2 TRAVERSAL
1) POSTORDER: for dp1 and also caculate second_dp1 
2) PREORDER: for dp2 using dp1 and second_dp1


WHAT IS second_dp1? and why do we need it

as in most cases dp2[c]=operator(dp1[p]+k1,dp2[p]+k2) 
we can see that this causes a problem if we go from p to c and this c only gave dp1 that answer
so thus we should keep a track of second_best dp1 this is second_dp1 only

SO, dp2[c]=operator(dp1[p]+k1,dp2[p]+k2)  if this c didnt give dp1 answer
else dp2[c]=operator(second_dp1[p]+k1,dp2[p]+k2)

    P 
C1      C2  outside answer for c1 can be both outside P and inside P due to C2

for ex: 
TO calculate the maximum distance of node for each node
    
*/

// preorder as for answer of parent we need answer of children
void dfs1(int u,int p,vector<vector<int>>&adj,vector<int>&dp1,vector<int>&second_dp1){
	for(auto v:adj[u]){
		if(v==p) continue;
		dfs1(v,u,adj,dp1,second_dp1);
	}
	for(auto v:adj[u]){
		if(v==p) continue;
		int cans=dp1[v]+1;
		if(cans>=dp1[u]){
			second_dp1[u]=dp1[u];
			dp1[u]=cans;
		}else if(cans>second_dp1[u]){
			second_dp1[u]=cans;
		}
	}
}
// postoder as for answer of childe we need answer of parent
void dfs2(int u,int p,int to_p,vector<vector<int>>&adj,vector<int>&dp2,vector<int>&dp1,vector<int>&second_dp1){
	if(p!=-1){
		dp2[u]=max(dp2[p]+1,to_p+1);
	}
	for(auto v:adj[u]){
		if(v==p) continue;
		if(dp1[u]==dp1[v]+1) //this child gave root the answer so use second best choice
		dfs2(v,u,second_dp1[u],adj,dp2,dp1,second_dp1);
		else
		dfs2(v,u,dp1[u],adj,dp2,dp1,second_dp1);

	}
}