/*
lps stands for longest prefix suffix lps[i] has the length of longest prefix of s[0.....i] that is also a suffix
i.e if lps[i]=x
s[0...x-1]=s[i-x.....i]
lps can be computed in linear time using 2 pointers
it can be used for string matching in linear seach using KMP
*/

vector<int> get_lps(string &s) {
    int m = s.size();
    vector<int> lps(m, 0);
    int len = 0; // Length of the previous longest prefix suffix
    int i = 1;
    while (i < m) {
        if (s[i] == s[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];//try the lps of this 
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

void KMPsearch(string &text, string &pattern) {
    int n = text.size();
    int m = pattern.size();
    vector<int> lps = computeLPS(pattern);
    
    int i = 0, j = 0; 
    while (i < n) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        }
        if (j == m) {
            j = lps[j - 1];//found the pattern in text
        } else if (i < n && text[i] != pattern[j]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
}
