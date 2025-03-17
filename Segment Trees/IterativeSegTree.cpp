/*
Array uses 0 based indexing segement tree used 1 based indexing
lc of i is 2*i(even)
rc of i is 2*i+1(odd)
parent of node i/2

max size required is 2*n
for each array index its mapped to index+=n in segment tree

*/

struct SegTree{
	int n;
	vector<int> st;
	SegTree(int size){ //bv base value what to return if no elements
        n=size;
		st.assign(2*n,0); //iterative segment tree using 1 based indexing
	}
	int merge(int lval,int rval){
		return max(lval,rval); //update based on the operator
	}
	void update(int idx,int val){
		idx+=n;//leaf node index
		st[idx]=val;
		while((idx/2)>=1){
			int p=idx/2;
			st[p]=merge(st[2*p],st[2*p+1]);
			idx=p;
		}
	}
	int query(int l, int r) {
		l+=n;r+=n;
		int ans=0;
		while(l<=r){
			if(l%2==1){
			ans=merge(ans,st[l]);//right child thus only pick the element
			l++;
			}
			if(r%2==0){
				ans=merge(ans,st[r]);//left child thun only pick the element;
				r--;
			}
			l=l/2;
			r=r/2;
		}
		return ans;
	}
};