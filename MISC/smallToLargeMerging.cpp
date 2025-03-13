/*
Whenever merging two sets always merge the smaller one into the bigger one.
IF doing random merging TC: O(n^2 logn)
each value can go to n sets and each merge takes n log n time,
 
IF we do Small To Large Merging 
TC: O(n logn^2)
as if smaller set has size x than after meging the size of set must be >2*x 
so if element gets moved y time it has to be in a set of 2^y set and 2^y can be at most n

thus y can be at most log n
*/


//EXAMPLE: Distinct Cols Problem: in nlogn^2
set<int> dfs(int curr,int par,vector<int> &ans,vector<vector<int>>&adj,vector<int>&cols){
	set<int> subset_cols={cols[curr]};
	for(auto nxt:adj[curr]){
		if(nxt!=par){
			set<int> nxt_cols=dfs(nxt,curr,ans,adj,cols);
			if(subset_cols.size()<nxt_cols.size())
				swap(subset_cols,nxt_cols); // O(1) swap just doing pointer swaps, for set for some DS not as simple swap
			for(auto col:nxt_cols)
				subset_cols.insert(col);
		}
	}
	ans[curr]=subset_cols.size();
	return subset_cols;
}
