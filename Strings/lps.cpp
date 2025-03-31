/*
lps stands for longest prefix suffix lps[i] has the length of longest prefix of s[0.....i] that is also a suffix
i.e if lps[i]=x
s[0...x-1]=s[i-x.....i]
lps can be computed in linear time using 2 pointers
it can be used for string matching in linear seach using KMP
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
bool KMPsearch(string &s, string &pat) {
    int n = s.size();
    int m = pat.size();
    vector<int> lps = get_lps(pat);
    int i = 0, j = 0; 
    while (i < n) {
        if (s[i] == pat[j]) {
            i++;
            j++;
            if(j==m)
                return true;
        }
        else {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    return false;
}
