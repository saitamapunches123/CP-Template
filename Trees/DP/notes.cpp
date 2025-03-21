/*
On doing dp on trees we try to process the sub trees first and using the all the child subtress answer get answer for whole tree


IF we need answer of children sub tree to get answer for full tree
POSTORDER TRAVERSAL
*/

void dfs1(int u,int p,vector<vector<int>>&adj,vector<int>&dp1{
	for(auto v:adj[u]){
		if(v==p) continue;
		dfs1(v,u,adj,dp1);
	}
	for(auto v:adj[u]){
		if(v==p) continue;
        dp1[u]=max(dp1[u],dp1[v]);//using answer of all sub tree get answer for the whole tree
	}
}


/* 
IF we need answer of parent to get answer for childen 
PREORDER TRAVERSAL
*/