/*
LIS or longest increasing subsequence is to get the longest strictly increasing subsequence in an array this can be solved in dp in O(n^2) time

but can be solved in O(nlogn) time using binary search
*/

// nlogn solution
vector<int> get_lis(vector<int> &a){
  vector<int> lis;
  for (auto x:a) {
      auto it = lower_bound(lis.begin(), lis.end(), x);
      if (it == lis.end())
          lis.push_back(b);
      else
          *it = b;
  }
  return lis;
}