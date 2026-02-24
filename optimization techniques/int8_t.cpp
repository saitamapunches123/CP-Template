/*
int are 4 bytes 32 bits.
What if we dont want to use all of the 4 bytes and just want to use 1 byte?
For ex:
if we want to sotre 2 states of dp
1) not calculated
2) true
3) false

using int we would need 4 bytes but using int8_t we can do it in 1 byte
*/

int8_t dp[2501][2501][2];
vector<vector<int8_t>> dp(n,vector<int8_t>(n,-1));


int8_t -> 8 bit integer
int16_t -> 16 bit integer
int32_t -> 32 bit integer (same as int)
int64_t -> 64 bit integer (same as ll)


https://leetcode.com/contest/weekly-contest-489/problems/longest-almost-palindromic-substring/description/