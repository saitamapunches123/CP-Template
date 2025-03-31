/*
Convolution can be helpfull to count the number of pairs in A[] with sum req many times.
can be usefull only if all elemnts in A[] are less than 1e6 as we need a frequency array and convolution on it 
*/

//freq is the frequency vector of A
vector<ll> c=convolution_ll(freq,freq);

/*
WHY THIS WORKS? 
as
c0=freq[0]*freq[0]
c1=freq[1]*freq[0]+freq[0]*freq[1]
c2=freq[2]*freq[0]+freq[1]*freq[1]+freq[0]*freq[2]
and so on....

PS1: as we can see c1 has freq[1]*freq[0]+freq[0]*freq[1] thuse Ck has number of ordered pais that is (1,3) and (3,1) are different pairs
     to get number of unorderd pairs just divide by 2
PS2: we need to adjust the count if the req is even as number of pairs with sum 0 is not freq[0]*freq[0] but freq[0]P2
     have made the adjustment below 
*/

ll num_ordered_pairs(ll req,vector<ll> &c,vector<ll> &freq){ //order important
	ll ans=c[req];
	if(req%2==0 and freq[req/2]>0){//for even need to recalculate freq[k/2]*freq[k/2] term
		ans-=freq[req/2]*freq[req/2];
		ans+=freq[req/2]*(freq[req/2]-1);
	}
	return ans;
}
ll num_unordered_pairs(ll req,vector<ll> &c,vector<ll> &freq){  //order not important
    return num_ordered_pairs(req,c,freq)/2;
}