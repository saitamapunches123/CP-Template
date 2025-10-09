/*
Lambda functions are anonymous functions that can be defined and used inline. They are useful for defining small, simple functions and we dont need to pass parameters to them

FOR EXAMPLE:
*/
void solve()
{	
  vector<ll> ps(n);
   auto P=[&](int ind)->ll{// here the & is used to capture the variables in the scope of the lambda function
    if(ind<0)
      return 0;
    return ps[ind];
   };
}