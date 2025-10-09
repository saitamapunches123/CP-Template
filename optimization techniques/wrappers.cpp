/*
Every DS is just a wrapper over another DS.
as vector is a wrapper over array, deque is a wrapper over vector, list is a wrapper over deque and so on.
This might be fine for corporate world but for competitive programming can lead to TLE /MLE 

FOR EXAMPLE:
vector<deque<int>> gave mle https://codeforces.com/contest/2145/submission/342270145
but  vector<vector<int>> worked https://codeforces.com/contest/2145/submission/342276992

thus try to use the most basic ds possible for the problem for now we can consider vector as a stable DS and use it and not prefer to use deque stack 
and implement them ourselves if needed

to implement queue using vector just keep an index of the front  push element at the back
*/