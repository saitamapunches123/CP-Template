
/*
    array<int,4> Allows to create states of fixed size. It is faster than using   vector<int> as it is a fixed size array
    If the states are of different types use tuple<int,char,double,int> 
    array<int,4> Supports both structured binding
    and indexing 
*/
vector<array<int,4>> deltas={{0,1,0,1},{0,-1,1,0},{-1,0,0,0},{1,0,0,0}};
for(auto [dr,dc,dlm,drm]:deltas){
  
}

deltas[0] // works also