long double ans; 
long double min_error=1e-5; // the min_error (tolerance of problem).
while(high-low>=min_error){
    long double mid=(low+high)/2;
    if(isValid(mid))
    { 
        ans=mid;
        low=mid;
    }else{
        high=mid;
    }
}

/*OR 
as each time we half the width let W be initial width and numbe of iteration required be x.
So
W/(2^x)<=min_error
W/min_error<=2^X use this and get lower bond on x and run the binary seach x times
*/

ll x=50;
for(int i=0;i<x;i++){
    long double mid=(low+high)/2;
    if(isValid(mid))
    { 
        ans=mid;
        low=mid;
    }else{
        high=mid;
    }
            
}