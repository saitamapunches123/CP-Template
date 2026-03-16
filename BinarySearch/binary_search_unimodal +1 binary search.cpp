/*
------------------------------------------------------------
Binary Search on Unimodal / Convex Function (Discrete)

Used when:
    f(x) decreases then increases
    or increases then decreases

Shape:
        ^
       / \
      /   \
-----/     \-----

For minimum finding:
    if f(mid) <= f(mid+1)
        answer lies in [l, mid]
    else
        answer lies in [mid+1, r]

Time Complexity:
    O(log(R-L) * cost_of_f)

Common Problems:
    - Minimum cost alignment
    - Weighted median problems
    - Minimize sum of distances
    - Convex DP optimizations
------------------------------------------------------------
*/

// Finding the minimum of a unimodal function
ll ans=LLONG_MAX;
while(l<=r){
    int mid=(l+r)/2;

    ll cost_mid=cost(mid);
    ll cost_mid1=cost(mid+1);

    if(cost_mid<=cost_mid1)
        r=mid-1;
    else
        l=mid+1;
}



/*
Example usage:

vector<int> h,c;

auto cost=[&](int x){
    long long res=0;
    for(int i=0;i<h.size();i++)
        res+=1LL*abs(h[i]-x)*c[i];
    return res;
};

int ans=unimodal_binary_search(0,max_height,cost);

*/