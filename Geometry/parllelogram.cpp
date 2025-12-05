/*
Properties of a parallelogram:
1) Opposite sides are equal and parallel
2) Diganoals Bisect each other

Thuse if we want to calculate total number of parallelograms in a set of points we can do it by
*/
// when dealing with slopes use this function and not double as it can lead to precision errors
pair<int,int> normalize_dir(int dy,int dx){ // to normalize we will always keep dx>=0 making (-1,2) and (1,-2) same
  if(dx<0 or (dx==0 and dy<0)){
      dx=-dx;
      dy=-dy;
  }
  int g=gcd(abs(dx),abs(dy));
  if(g!=0){
      dx=dx/g;
      dy=dy/g;
  }
  return {dy,dx};
}
// for points p1,p2,p3,p4 to form a parallelogram mid point of  p1p4 and p2p3 should be same (diagnoals bisect and direction of p1p4 and p2p3 should not same)
ll countParallelograms(vector<pair<int,int>> &points){
  map<pair<int,int>,map<pair<int,int>,int>> mp;
  int n=points.size();
  for(int i=0;i<n;i++){
      auto [x1,y1]=points[i];
      for(int j=i+1;j<n;j++){
          auto [x2,y2]=points[j];
          int mx=x2+x1,my=y2+y1;// get mid point of diagonals
          int dx=x2-x1,dy=y2-y1;
          auto dir=normalize_dir(dy,dx);//direction/slope of diagonals
          mp[{mx,my}][dir]++;
      }
  }
  ll ans=0;
  for(auto &[p,dir_mp]:mp){
      ll tot=0;
      for(auto &[dir,cnt]:dir_mp){
          ll cans=cnt*tot;
          ans+=cans;
          tot+=cnt;
      }
  }
  return ans;
}