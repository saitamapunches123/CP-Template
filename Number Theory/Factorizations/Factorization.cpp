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