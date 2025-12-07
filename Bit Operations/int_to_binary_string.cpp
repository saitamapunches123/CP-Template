string toBinary(long long n) {
  if (n == 0) return "0";
  string s = "";
  while (n > 0) {
      s += char('0' + (n & 1));
      n >>= 1;
  }
  reverse(s.begin(), s.end());
  return s;
}



int toInt(string &s){
  int ans=0;
  for(auto c:s)
      ans=ans*2+(c-'0');
  return ans;
}
