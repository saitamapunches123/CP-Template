#include <bits/stdc++.h>
using namespace std;
#include <algorithm> // sqrtl() __gcd() 
#include <numeric>
#include <cmath>
#include <iomanip>//to do setprecision(3)
// #define int long long //if you think the code is overflowing uncomment this all int will be long long
#define ll long long 
#define ld long double
#define LLMAX LLONG_MAX
#define LLMIN LLONG_MIN
using tii=tuple<int,int,int>;
using pii=pair<int,int>;
//pow(2LL,n)
//float< double< long double
//10^9+7=1e9+7
//stoi, stoll(for long long)
/* 
1) You can do it!! because you have done it before.
2) Dont worry today might not be your day.
3) Start Fresh, Dry Run, Do Maths if you get stuck.
4) Re-Write full code if implementation gets lenghty.
*/
const double eps = 1e-9;
const string Yes = "Yes", No="No", Alice="Alice", Bob="Bob";
template<typename T>
void display(initializer_list<T> v) {
		for (auto& x : v)
				cout << x << " ";
		cout << endl;
}
template<typename T>
void display(const vector<T>& v) {
	for (const auto& x : v)
			cout << x << " ";
	cout << endl;
}

vector<vector<int>> make2D(int n, int m, int val=0) {
	 return vector<vector<int>>(n, vector<int>(m, val));
}
// 	auto dp=make3D(10,20,30,-1);
vector<vector<vector<int>>> make3D(int n, int m, int k, int val=0) {
	 return vector<vector<vector<int>>>(n, vector<vector<int>>(m, vector<int>(k, val)));
}
void compute() { // compute() fn only runs once.

}
/*
	if need to debug a test case (for ex: to debug test case 10)
	if(tc==10)
		print intput in 1 concatenated(. or ,) string(no space or line)	
*/
void solve(int tc) {

}

void fast() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}
signed main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fast();
	compute();
	int t;cin>>t;
	for(int tc=1;tc<=t;tc++){
		// cout<<tc<<":"<<endl;
		solve(tc);
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