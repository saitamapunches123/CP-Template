/*
Codrinate compression is usefull when we need to create a frequency map or mark each value to something
but if the array values are in range 1e9 (cant create a vector where index acts as key).
AND unordered_map is unreliable map requires log factor

SOLUTION: Cordinate Compression

The idea is as the number of values will be in range 1e5 we can match each of the value to 1e5
as number of values is 1e5
*/

vector<int> cordinateCompression(vector<int> &a){
	int n=a.size();
	set<int> vals(a.begin(),a.end()); // create a set sorted form of the vector
	vector<int> compressed(vals.begin(),vals.end());
	vector<int> ans(n);
	for(int i=0;i<n;i++)
		ans[i]=lower_bound(compressed.begin(),compressed.end(),a[i])-compressed.begin(); //find each a[i] value in compressed vector
	return ans; //this will only have value from 0 to n-1
}

/*
EXAMPLE:

arr = {100, 200, 1000, 200, 500}
Step-by-step Compression:
1. Extract unique values: {100, 200, 1000, 5000}
2. Sort them: {100, 200, 1000, 5000}
3. Assign compressed values: 
    100  -> 0
    200  -> 1
    1000 -> 2
    5000 -> 3
4. Replace original values with compressed ones.

Output: {0, 1, 2, 1, 3}

*/