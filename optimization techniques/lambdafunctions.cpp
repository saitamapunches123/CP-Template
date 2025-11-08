/*
Lambda functions are anonymous functions that can be defined and used inline. They are useful for defining small, simple functions and we dont need to pass parameters to them

PS: they are not effecient and are slower than normall functions so dont use for recursion.
FOR EXAMPLE:
*/

vector<ll> ps(n);
auto P=[&](int ind)->ll{// here the & is used to capture the variables in the scope of the lambda function
  if(ind<0)
    return 0;
  return ps[ind];
};
// now can do P(i) to get the value of ps[i]
 
//NOTE for recusive function auto wont work
function<ll(int)> recur=[&](int i)->ll{// here auto wont work use 
  if(i==n)
      return 0;
  ll pick=a[i];
  int j=i+1;
  for(;j<n;j++){
      if(abs(a[i]-a[j])<=2)
          continue;
      break;
  }
  pick+=recur(j);
  ll not_pick=recur(i+1);
  return max(pick,not_pick);
};
return recur(0);

