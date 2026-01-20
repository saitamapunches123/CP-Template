int gcd_array(vector<int> &arr){
  int g=arr[0];
  for(auto x:arr)
    g=gcd(g,x);
  return g;
}
