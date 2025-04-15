/*
SEG tree on indexes is hepfull when u need to know the number of vals to the right/left of an element that is greater/lesser than it.alignas

FOR example giving array for each index find the number of values on its right less than it.

We can use a sum segment tree here and sort the values of array than for each value

ans[i]=sum[i,...n] as only elements with value less than arr[i] is set till now

*/

struct SegTree{
    int n;
    vector<int> st;
    SegTree(int size){ //bv base value what to return if no elements
        n=size;
        st.assign(2*n,0); //iterative segment tree using 1 based indexing
    }
    int merge(int lval,int rval){
        return lval+rval; //update based on the operator
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
vector<int> countSmaller(vector<int>& nums) {
    int n=nums.size();
    map<int,vector<int>> mp;
    for(int i=0;i<n;i++)
    mp[nums[i]].push_back(i);
    vector<int> ans(n);
    SegTree obj(n);
    for(auto &[val,idxs]:mp){
        for(auto idx:idxs){
            ans[idx]=obj.query(idx,n-1);// as we are processing queries in sorted order by values thus only indexes with value less than curr_Val will be set
        }
        for(auto idx:idxs){
            obj.update(idx,1);
        }
    }
    return ans;
}

/*
SAMPLE USE:->
in a problem lets say you have two arrays arr1 and arr2 and you for each val
you need to find common vals that are to left of val in both arr1 and arr2
EX:
arr1 = [3, 1, 4, 2, 5]  
arr2 = [1, 3, 5, 2, 4]

for val=2 {1,3} are in left of 2 in both arr1 and arr2
*/

/*
How to solve it??
create a segment tree on arr2 than traverse the nums 1 from left to right 
int x=arr1[i];
int j=look_up[x]; // llok_up table on arr2 so x is at j index in arr2
int common_elms=sum[0,...j-1] //get sum of segment tree 
set[j]=1

this works as we are only seeting 1s to the elements that are in  left of x in nums1 thus
sum [0,..j-1] gives in total how many element are common to the left
*/