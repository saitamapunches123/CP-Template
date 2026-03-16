// here a=x+y and b=x-y so x=(a+b)/2 y=(a-b)/2
// returns number of total paths from (a1,b1) to (a2,b2) or from (x1,y1) to (x2,y2)
int num_paths(Combinatorics &obj,int a1,int b1,int a2,int b2){
  return obj.nCr(a2-a1,(a2+b2-a1-b1)/2);
}
// returns number of valid paths from (x1,y1) to (x2,y2) i.e they do'nt intersect diagonal
int num_valid_paths(Combinatorics &obj,int x1,int y1,int x2,int y2){
  // step1) convert to (A,B) where A=x+y , B=x-y (helps in finding the mirror and easy to visualize)
  int a1=x1+y1,b1=x1-y1,a2=x2+y2,b2=x2-y2;
  // step2) Let s(a1,b1) here the invalid line is x-y=1 => B=-1 reflection of s(a1,b1) along B=-1 s'(a1,-b1-2) as b1-(-1)==(-1)-(-b1-2)
  int ma1=a1,mb1=-b1-2; // mirror/reflection of (a1,b1) along B=-1 (invalid axis)
  // step3) Ans=Total-invalid=Paths(s->t)-Paths(s'->t)
  int ans=(num_paths(obj,a1,b1,a2,b2)+mod-num_paths(obj,ma1,mb1,a2,b2))%mod;
  return ans;
}


// We can convert a lot of problems into finding the number of valid paths from (x1,y1) to (x2,y2)
// For ex: number of valid paranthesis of length n let ( be x and ) be y then we need to find the number of valid paths from (0,0) to (n,n) where x>y at any point of time or we never cross the diagonal.
//Reference: https://www.youtube.com/watch?v=M5PbeUrOsDw&t=2967s
// https://cses.fi/problemset/task/2187