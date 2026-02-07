/*
Always rememer:

DFS: Lexiographically smallest
BFS: Numerically smallest

for ex: 
if we want to find the lexiograpically smallest number with sum of digits equal>=10 1111111111 is the answer using dfs.
but if we want the smallest number with sum of digits equal>=10 29 is the answer using bfs.
*/


// bfs gives us numerically minimal
while(q.size()>0){
  auto [last,mod]=q.front();q.pop();
  if(mod==0 and last>0){
    string ans=to_string(last);
    int d=last,m=mod;
    while(true){
      auto [nd,nmod]=choices[d][m];
      if(nd==0)
        break;
      ans+=to_string(nd);
      d=nd;
      m=nmod;
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
    return;
  }
  for(int d=last;d<=9;d++){
    int nmod=(mod*10+d)%n;
    if(vis[d][nmod]==false){
      vis[d][nmod]=true;
      choices[d][nmod]={last,mod};
      q.push({d,nmod});
    }
  }
}
cout<<-1<<endl;

-> https://atcoder.jp/contests/abc443/tasks/abc443_f