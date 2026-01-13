vector<int> get_pse(vector<int> &a){
  int n=a.size();
  vector<int> pse(n, -1); 
    stack<int> st;
    for (int i = n-1; i >=0 ; i--) {
        while(st.size()>0 and a[i]<a[st.top()]){
          int j=st.top(); st.pop();
          pse[j]=i;
        }
        st.push(i);
    }
    return pse;
}
vector<int> get_nse(vector<int> &a){
  int n=a.size();
  vector<int> nse(n, n);
    stack<int> st;
    for (int i = 0; i <n ; i++) {
        while(st.size()>0 and a[i]<a[st.top()]){
          int j=st.top(); st.pop();
          nse[j]=i;
        }
        st.push(i);
    }
    return nse;
}


/*
  number of subarray where nums[i] is min  = (i-pse[i])*(nse[i]-i) 
  as there could be multiple same min to avloid change one of nse or pse to a[i] <=a[st.top()] to avoid overcouning.
  for example: 3,4,3,2
  pse=[-1,0,0,3] here using pse<=nums[i]
  nse=[3,2,3,4] here using nse<nums[i]
  number of subrray where nums[0] is min = (0--1)*(3-0)=3
  number of subrray where nums[2] is min = (2-0)*(3-2)=2

*/
https://codeforces.com/contest/2184/problem/E