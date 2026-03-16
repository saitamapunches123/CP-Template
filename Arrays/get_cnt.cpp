// returns number of values in a sorted array s.t x<=a[i]<=y
int get_cnt(vector<int> &a,int x,int y){
  auto it=upper_bound(a.begin(),a.end(),y);
  auto pit=lower_bound(a.begin(),a.end(),x);
  return it-pit;
} 