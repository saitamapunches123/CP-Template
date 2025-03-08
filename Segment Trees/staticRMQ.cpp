/*

TO perform queries of the form min(l,r)=> min(a[l],a[l+1],a[l+2],.....a[r]) for an OFFLINE (STATIC ARRAY).
i.e no change in array can be done.


these queries can be done in O(1) time using O(nlogn) build function
thus we can use this over seg trees if q>n (number of queries is more than size of array).

NOTE: prefix doesnt work for finding range max/min

HOW THIS WORKS?
comput look_up[][] table 
where look_up[i][j]=min(a[i],a[i+1],...a[(i+2^j)-1]) at build
than,
for query(i,j) just consider two segements one starting at i other ending at j and both of the maximum posible 2^k such that inside segement i,j
*/


struct StaticRMQ
{
	vector<vector<int>> look_up;
	int sz;
	StaticRMQ(vector<int> &a){
		sz=a.size();
		int log_sz=log2(sz)+1;
		look_up.assign(sz, vector<int>(log_sz));
		build(a);
	}

    void build(vector<int>& a) {
        // Base case: Filling the first column (2^0 = 1-length intervals)
        for (int i = 0; i < sz; i++)
            look_up[i][0] = a[i];

        // Interval look_up[i][j]=min(a[i],a[i+1],....a[i+2^j-1])
        for (int j = 1; (1 << j) <= sz; j++) { 
            for (int i = 0; (i + (1 << j) - 1) < sz; i++) {
            	// as 2^x=2^x-1+2^x-1
                look_up[i][j] = min(look_up[i][j - 1], look_up[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

	int query(int l,int r){
		int curr_sz=r-l+1;
		int j=log2(curr_sz);
		int ans=look_up[l][j];
		int start_end=r-(1<<j)+1;
		ans=min(ans,look_up[start_end][j]);
		return ans;
	}
	
};


/*
HOW TO USE?
StaticRMQ obj(a); // a is the static array
int ans=obj.query(l,r);

PS: log2(n) is computed in O(1) time.
*/