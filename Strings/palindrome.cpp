/*
A string can be shuffled into a palindrome if all characters have even frequency and at most one character has odd frequency

for even length -> all character should have even frequency
for odd length -> 1 character can have odd frequency and we can do (.....ch..... ch is odd frequency charachter)

To find the longest palindrome prefix of a string: (for longest plaindrome suffix just reverse s and do the same steps)

1) DO t=s+'#'+rev(s)
2) find lps of t let lps.back()=j
this means s[0]s[1]....s[j-1]=s[j-1]s[j-2]......s[1]s[0] thus j is the length of longest palindrome prefix of s
*/
vector<int> get_lps(string &s) {
    int n = s.size();
    vector<int> lps(n, 0);
    int j = 0;

    for (int i = 1; i < n; i++) {
        while (j > 0 && s[i] != s[j]) {
            j = lps[j - 1]; 
        }
        if (s[i] == s[j]) {
            j++;
            lps[i] = j;
        }
    }
    return lps;
}
int get_max_pali_pref(string &s){ //need to find the longest prefix of this string which is a palindrome
	string rev=s;
	reverse(rev.begin(),rev.end());
	string t=s+'#'+rev;
	vector<int> lps=get_lps(t);
	int max_pali_pref=lps.back();
    return max_pali_pref;
}