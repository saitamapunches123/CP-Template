/*
Pre computation technique works simillar to a function 

pre computation works in O(n) time

than you can find max_palindrome centered at i of odd length and even lenth in O(1)
also can check if l,r is palindrom in O(n)
*/ 


//TC: O(n)  SC:O(n) for pre computation
struct Manacher {
    public: 
    // dp[i] = radius of longest palindrome centered at i in transformed string
    vector<int> dp;    
    string ms,orignal;        
    Manacher(string &s) {
        orignal=s;
        ms = "@#"; 
        for (char c : s) {
            ms += c;
            ms +='#';
        }
        ms += "$"; 
        runManacher();
    }

    void runManacher() {
        int n = ms.size();
        dp.assign(n, 0);
        int l = 0, r = 0;
        for (int i = 1; i < n - 1; ++i) {
            int mirror = l + r - i;
            // dp[i] should atlease be this based on mirror value
            if (i < r)
                dp[i] = min(r - i, dp[mirror]);
            // expand palindrome
            while (ms[i + 1 + dp[i]] == ms[i - 1 - dp[i]])
                dp[i]++;
            // best bound is the one with max r
            if (i + dp[i] > r) {
                l = i - dp[i];
                r = i + dp[i];
            }
        }
    }

    // returns length of longest palindrome centered 
    // at 'cen' in original string
    int getLongest(int cen, bool odd) {
        //map to dp index
        int pos = 2 * cen + 2 + !odd;
        return dp[pos];
    }

    // checks if s[l..r] is a palindrome
    bool is_pali(int l, int r) {
        int len = r - l + 1;
        int cen = (l + r) / 2;
        return len <= getLongest(cen, len % 2);
    }
    string get_biggest_pali(){
        int m=orignal.size(),st=-1,max_len=-1;
        for(int i=0;i<m;i++){
            int odd_len=getLongest(i,1),even_len=getLongest(i,0);
            if (odd_len > max_len) {
                max_len = odd_len;
                st = i - max_len / 2;
            }
            if(even_len>max_len){
                max_len = even_len;
                st = i - max_len / 2+1;
            }
        }
        return orignal.substr(st,max_len);
    }
};
