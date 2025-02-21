map<int,int> freq;
for(auto x:a)
    freq[x]++;

// to get number of elements for all numbers from [min_g,max_g]
//TC: let k=max_g-min_g O(k logk) as K+K/2+K/3+K/4+..... harmonic series
for(ll g=min_g;g<=max_g;g++){
    ll num_terms=0;
    ll x=g;
    while(x<=mv){
        num_terms+=freq[x];
        x+=g;
    }

}