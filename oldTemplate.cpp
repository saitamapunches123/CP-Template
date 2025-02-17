#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#include <algorithm> // sqrtl() __gcd() 
#include <numeric>
#include <cmath>
#include <iomanip>//to do setprecision(3)
//pow(2LL,n)
//float<double<long double
//10^9+7=1e9+7
struct custom_hash {
	static uint64_t splitmix64(uint64_t x) {
		// http://xorshift.di.unimi.it/splitmix64.c
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}

	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};
// to create random hash (otherwise someone can hack the soln as by default deterministic hash fn used by cpp)
//unordered_map<ll, int, custom_hash>mp;


/*
To get all divisors of 2 to n in nlog(n)
vector<vector<ll>>divs(k+1);
for(ll i=2;i<=k;i++)
{
	for(ll j=i;j<=k;j+=i)
		divs[j].push_back(i);
}
*/

ll getPrime(ll n)// returns the least divisor of n if n is prime returns n
{
	if (n % 2 == 0)
		return 2;
	for (ll i = 3; i <= sqrt(n); i = i + 2)
	{
		if (n % i == 0)
			return i;
	}
	return n;
}
//doesnt include 1 as a factor
void primeFactors(int n, unordered_map<int, int>&facts)
{
	while (n % 2 == 0)
	{
		facts[2]++;
		n = n / 2;
	}
	for (int i = 3; i <= sqrt(n); i = i + 2)
	{
		while (n % i == 0)
		{
			facts[i]++;
			n = n / i;
		}
	}
	//n is a prime
	if (n > 2)
		facts[n]++;
}

//Binary exponeantation
ll mod_exp(ll base, ll exp, ll mod) {
    ll res = 1;
    while (exp > 0) {
        if (exp % 2 == 1)
            res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

//If mod is prime
//a^−1 MOD=a^(MOD−2) MOD
ll mod_inv(ll x, ll mod) {
    return mod_exp(x, mod - 2, mod); // Only works if mod is prime
}

vector<int> getBinaryRepresentation(int num) {
    vector<int> binary;
    while (num > 0) {
        binary.push_back(num % 2); // Extract the least significant bit
        num /= 2; // Right shift the number
    }
    // reverse(binary.begin(), binary.end()); // Reverse to get the correct order
    return binary;
}

ll maxXOR(int l, int r) {
    // Compute XOR of l and r
    int x = l ^ r;
    
    // Find the position of the most significant bit (MSB) where l and r differ
    int msb = 0;
    while (x > 0) {
    	// cout<<x<<endl;
        msb++;
        x >>= 1;
    }

    // Compute the maximum XOR by setting all bits below MSB to 1
    return msb-1;
}
vector<int> getBits(int num) {
    vector<int> bits(32, 0); // Initialize a vector of size 32 with 0
    for (int i = 31; i >= 0; i--) {
        bits[i] = (num & 1); // Get the least significant bit
        num >>= 1;          // Right shift the number
    }
    return bits;
}
int vectorToInt( vector<int>& bits) {
    int num = 0;
    for (int i = 0; i < 32; i++) {
        num = (num << 1) | bits[i]; // Left shift and add the current bit
    }
    return num;
}
/* 
You can do it!! because you have done it before.
Dont worry today might not be your day.
Start Fresh, Dry Run, Do Maths if you get stuck
*/
void solve()
{	

	
}
void fast() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fast();
	int t;
	cin >> t;
	while (t--)
	{
		// cout << t;
		solve();
	}
	//int x=10,a=3;
	//double d =ceil((1.0*x)/a);
	//cout <<fixed<< setprecision(22) << d;
	//fixed keeps the data in numeric and not scientefic i.e (1e)
}
/*
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⣠⣶⡾⠏⠉⠙⠳⢦⡀⠀⠀⠀⢠⠞⠉⠙⠲⡀⠀
⠀⠀⠀⣴⠿⠏⠀⠀⠀⠀⠀⠀⢳⡀⠀  ⡏⠀⠀⠀⠀⠀⢷
⠀⠀⢠⣟⣋⡀⢀⣀⣀⡀⠀⣀⡀⣧⠀⢸⠀⠀⠀⠀⠀ ⡇
⠀⠀⢸⣯⡭ ⠸⣛⣟⠆⡴⣻⡲⣿⠀⣸⠀⠀OK⠀ ⡇
⠀⠀⣟⣿⡭⠀⠀⠀⠀⠀⢱⠀⠀⣿⠀ ⢹⠀⠀⠀⠀⠀ ⡇
⠀⠀⠙⢿⣯⠄⠀⠀⠀⢀⡀⠀⠀⡿⠀⠀⡇⠀⠀⠀ ⠀⡼
⠀⠀⠀⠀⠹⣶⠆⠀⠀⠀⠀⠀⡴⠃⠀⠀ ⠘⠤⣄⣠⠞⠀
⠀⠀⠀⠀⠀⢸⣷⡦⢤⡤⢤⣞⣁⠀⠀⠀ ⠀⠀⠀⠀⠀⠀⠀
⠀⠀⢀⣤⣴⣿⣏⠁⠀⠀⠸⣏⢯⣷⣖⣦⡀⠀⠀⠀⠀⠀⠀
⢀⣾⣽⣿⣿⣿⣿⠛⢲⣶⣾⢉⡷⣿⣿⠵⣿⠀⠀⠀⠀⠀⠀
⣼⣿⠍⠉⣿⡭⠉⠙⢺⣇⣼⡏⠀⠀⠀⣄⢸⠀⠀⠀⠀⠀⠀
⣿⣿⣧⣀⣿.........⣀⣰⣏⣘⣆⣀⠀⠀
*/