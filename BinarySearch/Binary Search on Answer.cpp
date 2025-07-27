// to get the minimum answer
while(l<=r){
    int mid=l+(r-l)/2;
    if(possible(mid))
        r=mid-1;
    else
        l=mid+1;
}
return l;



// to get the maximum answer
while(l<=r){
    int mid=l+(r-l)/2;
    if(possible(mid))
        l=mid+1;
    else
        r=mid-1;
}
return r;