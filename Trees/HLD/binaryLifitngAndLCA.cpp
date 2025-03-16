/*
Binary jumping can help you to find the  kth ancestor on a node in log(n) time
it uses the fact that all numbers can be represnetd as powers of 2
thus we can create a lookup table where up[i][j] has the 2^j ancestor of i 
up[i][0] is parent of i.

Size of table n*log(n) we can use this table to get any ancestor of node in logn time


TO GET LCA(a,b)
S1) MOVE a,b to same depth
S2) if a==b its lca
S3) start by largest power of 2 and see if its an common ancestor if yes it may not be lca so go to smaller power of 2
    if no move to that node
*/

struct BinaryJumpingLca{
	vector<vector<int>> up;
	vector<int> depth; // not needed if lca is not required
	int n,log_sz;
	BinaryJumpingLca(int sz){
		n=sz;
		log_sz=log2(sz)+2; 
		up.assign(n,vector<int>(log_sz));
		depth.assign(n,0);
	}
	void dfs(int curr,vector<vector<int>> &adj,int parr=-1,int d=0){
		depth[curr]=d;
		for(auto nxt:adj[curr]){
			if(nxt!=parr){
				up[nxt][0]=curr;//2^0 =1stparent can also set this while taking input
				dfs(nxt,adj,curr,d+1);
			}
		}
	}
	void fill_up(){
		for(int j=1;j<log_sz;j++){
			for(int i=1;i<n;i++){
				int v=up[i][j-1];
				if(v==-1)
					up[i][j]=-1;
				else
					up[i][j]=up[v][j-1];
			}
		}
	}
	// moves up curr k times
	int move_up(int curr,int k){
		for(int i=0;i<log_sz;i++){
			if(curr==-1)
				return -1;
			int rep=1<<i;
			if(k&rep){
				curr=up[curr][i];
			}
		}
		return curr;
	}
	int get_lca(int a,int b){
		//assuming a to be the below node
		if(depth[b]>depth[a])
			swap(a,b);
		int diff=depth[a]-depth[b];
		a=move_up(a,diff);
		if(a==b)
			return a;
		for(int i=log_sz-1;i>=0;i--){
			if(up[a][i]!=up[b][i]){
				a=up[a][i];
				b=up[b][i];
			}
			
		}
		return up[a][0];
	}
};

/*
HOW TO USE
BinaryJumpingLca obj(n+1);
obj.dfs(1,adj);
obj.fill_up();
obj.get_lca(u,v)
*/