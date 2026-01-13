vector<pii> spirallyTraverse(vector<string> &mat) {
  vector<pii> deltas={{0,1},{1,0},{0,-1},{-1,0}}; //Move right if possible if not move down if not move left if not move up
    int n = mat.size(),m=mat[0].size();
    vector<vector<bool>> vis(n,vector<bool>(m,false));
    queue<tii> q;
    q.push({0,0,0});
    vis[0][0]=true;
    vector<pii> ans;
    while(q.size()>0){
      auto [r,c,di]=q.front();q.pop();
      ans.push_back({r,c});
      for(int d=0;d<4;d++){
        int idx=(di+d)%4;
        auto [dr,dc]=deltas[idx];
        int nr=r+dr,nc=c+dc;
        if(nr>=0 and nr<n and nc>=0 and nc<m and vis[nr][nc]==false){
          vis[nr][nc]=true;
        q.push({nr,nc,idx});
        break;
      }
      }
    }
    return ans;
}
// In spiral order ans[i] is conected with ans[i-1] always and assigning in spiral order never disconects the graph
// https://codeforces.com/contest/1254/problem/A