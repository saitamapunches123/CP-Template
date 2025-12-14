/*
MOS queries are usefull ro process offline l,r queries on an array 
These follow sliding window technique thus using (l,r) 's answer we get (l+-1,r) (l,r+-1)'s Answer

NOTE: MO's queries are much slower than segment tree and is offline so only use it if creating segment and joining segmenet become hard
for example: QUERRY on number of unique values in (l,r)

MO's Algorithm works if:
1)  Array is static that is no update on array during processing of queries
2)  All queries are know beforehand as we batch the queries and process them together
3)  Using the answer for (l,r) we can calculate the answer for  (l,r-1) ,(l,r+1), (l-1,r), (l+1,r)

How does it work
1)  Sort all the queries in MO's order.
2)  Set mo_left to 0 and mo_right to -1.
3)  Now process each querry.
    i.e, l,r=querr[i] move mo_left and mo_right to l,r (this is why we need point 3).

TC: sorting querry according to MO's order gurantees that each index will go at max sqrt(n) times
thus TC: O((n+q)*sqrt(n)*f)
    f time take to go from (l,r) to (l+-1,r+-1) thus make

    AS n*sqrtn for n=1e5 is alsost 1e8 make sure that f is as minimal as possibe 
    (for ex using cordinate compression and vector instead of map)
*/



struct MosQueries{
	int qs,block_size;
	int mo_left=0,mo_right=-1;
	vector<int> window;
	int cans=0;

	//queries are in the form {l,r,querynumber} 
	// n is nums.size()
	MosQueries(vector<vector<int>> &queries,int n){
		qs=queries.size();
		block_size=sqrt(n);
		sort(queries.begin(),queries.end(),[this](auto &q1,auto &q2){
			int x1=q1[0]/block_size,x2=q2[0]/block_size;
			if(x1!=x2)
				return x1<x2;
			return (x1 &1 == 0) ? (q1[1] < q2[1]) : (q1[1] > q2[1]); // Also try just using if this TLEs : return q1[1]<q2[1]; 
		});
	}
	void remove(int x){
		window[x]--;
		if(window[x]==0)
			cans--;
	}
	void add(int x){
		window[x]++;
		if(window[x]==1)
			cans++;
	}
	int get_ans(vector<int> &a,int l,int r){
		while(mo_right<r){
			mo_right++;
			add(a[mo_right]);
		}
		while(mo_right>r){
			remove(a[mo_right]);
			mo_right--;
		}
		while(mo_left>l){
			mo_left--;
			add(a[mo_left]);
		}
		while(mo_left<l){
			remove(a[mo_left]);
			mo_left++;
		}
		return cans;
	}
	vector<int> process_queries(vector<int> &a,vector<vector<int>> &queries){
		int m=a.size();
		window.assign(m,0);
		vector<int> ans(qs);
		for(auto q:queries){
			int l=q[0],r=q[1],idx=q[2];
			ans[idx]=get_ans(a,l,r);
		}
		return ans;
	}
};


/*
Usage:

int n=arr.size();
MosQueries obj(nqueries,n);
vector<int> ans=obj.process_queries(arr,nqueries); //get answer of all the queries together
*/