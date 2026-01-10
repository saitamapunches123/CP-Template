// To get all divisors of 2 to n in nlog(n)
vector<vector<ll>>divs(k+1);
for(ll i=2;i<=k;i++)
{
	for(ll j=i;j<=k;j+=i)
		divs[j].push_back(i);
}


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