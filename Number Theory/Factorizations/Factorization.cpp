// To get all divisors of 2 to n in nlog(n)
vector<vector<ll>>divs(k+1);
for(ll i=2;i<=k;i++)
{
	for(ll j=i;j<=k;j+=i)
		divs[j].push_back(i);
}


bool is_prime(ll n) { // ROUGHLY EVERY log(n) values has a prime so in 1 to n there are n/log(n) primes
		if (n < 2) return false;
		if (n == 2) return true;
		if (n % 2 == 0) return false;
		for (ll x = 3; x * x <= n; x += 2) {
				if (n % x == 0) return false;
		}
		return true;
}


//doesnt include 1 as a factor
void primeFactors(int n, map<int, int>&facts)
{
	
	for (int i = 2; i <= sqrt(n); i++)
	{
		while (n % i == 0)
		{
			facts[i]++;
			n = n / i;
		}
	}
	//n is a prime
	if (n > 1)
		facts[n]++;
}