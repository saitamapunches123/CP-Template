/*
Euler Tour is usefull when you want to convert a tree into an array and perform range queries on it
Euler tour is done using dfs and using a root.

It's usefull when you want to perform operations on a sub tree this sub tree can be understood as a range and than we can perform range queries on it.
*/

void euler_tour(vector<vector<int>> &adj,int curr,int par,vector<int> &start,vector<int> &end,int &time){
	start[curr]=time;
	time++;
	for(auto x:adj[curr]){
		if(x!=par){
			euler_tour(adj,x,curr,start,end,time);
		}
	}
	end[curr]=time;
}
void euler_tour_wrapper(vector<vector<int>> &adj,int node,vector<int> &start,vector<int> &end){
    int time=0;
    euler_tour(adj,node,-1,start,end,time);
}

/*
As the start[node] for each node will be uniquq thus we can use this.
Also all elements with a start in [start[node],end[node]-1] must lie in the sub tree of node
Allowing us to queuery based on this.
*/