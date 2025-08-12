
/* 
z[i]-> gives the biggest substring starting at i i,e also a prefix
i.e s[0...z[i]]=s[i...i+z[i]]
l and r are z box limits such that s[l...r] is a prefix
*/
vector<int> z_function(string &s){
    int l=0,r=0,n=s.size();
    vector<int> z(n);
    z[0]=n;
    for(int i=1;i<n;i++){
        z[i]=max(0,min(z[i-l],r-i+1)); // l to r is prefix and 0 to l is prefix so  max prefix startning at i=min(z[i-l],r-i+1)
        while(i+z[i]<n and s[z[i]]==s[i+z[i]]){
            l=i;
            r=i+z[i];
            z[i]++;
        }
    }
    return z;
}
vector<int> get_matches(string &txt,string &pat){
    string s=pat+"#"+txt;
    int m=pat.size(),len=s.size();
    vector<int> z=z_function(s);
    vector<int> ans;
    for(int i=0;i<len;i++){
        if(z[i]==m)// z[i]= max length of substring starting at i i.e equal to prefix of s
            ans.push_back(i-m-1);
    }
    return ans;
}