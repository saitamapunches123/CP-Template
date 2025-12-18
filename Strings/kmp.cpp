vector<int> get_lps(string &s){
  int n=s.size();
  int i=1,len=0;
  vector<int> lps(n);
  while(i<n){
    if(s[i]==s[len]){
      len++;
      lps[i]=len;
      i++;
    }else{
      if(len==0){
        lps[i]=0;
        i++;
      }else
        len=lps[len-1];
    }
  }
  return lps;
}
bool kmp(string &s,string &pat){
  vector<int> lps=get_lps(pat); //longest prefix which is also suffix
  int i=0,j=0,n=s.size(),m=pat.size();
  while(i<n){
    if(s[i]==pat[j]){
      i++;j++;
      if(j==m)
        return true;
    }else{
      if(j==0)
        i++;
      else
        j=lps[j-1];
    }
  }
  return false;
}