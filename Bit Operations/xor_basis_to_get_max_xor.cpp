/*
XOR Linear Basis (USE FOR XOR OVER SUBSETS)

Use-case:
- Consider all possible XOR sums of all subsets of an array
- Find maximum XOR subset sum
- Check if a value is representable using subset XOR

Idea:
- Maintain a basis where each element has a unique highest set bit
- Similar to Gaussian elimination but for XOR (GF(2))
- basis[f] stores the number whose highest set bit is f
*/

/*
XOR basis is a minimal set of values such that every element of the array (and every XOR of its subsets) can be represented as the XOR of some subset of the basis.
*/


//USING GAUSIAN ELEIMANTION TO FIND MINIMAL SUBSET 
vector<int> get_xor_basis(vector<int> &arr) {
    /*
    basis[f] = number in the basis whose highest set bit is f
    If basis[f] == 0 → no such element exists yet
    */
    vector<int> basis(32, 0);

    for (int x : arr) { // as each x must be formed by basis
        for (int f = 31; f >= 0; f--) {
            int rep=1<<f; 
            if((rep&x)==0) continue; // If f-th bit is not set in x, skip

            /*
            If no basis element has highest bit f,
            we can store x here and finish
            */
            if (basis[f] == 0) {
                basis[f] = x;
                break; //only use it for its highest set bit
            }

            /*
            Otherwise, eliminate the f-th bit from x
            using the existing basis element
            */
            x ^= basis[f];
        }
    }

    // elements of basis are all basis[f] where basis[f] !=0 
    return basis;
}

// # of unique XOR sums = 2^ size of basis (as each basis element controls 1 number)
ll max_xor_subset_sum(vector<int> &basis) {
    
    ll xor_sum=0;
    //using greedy to get the maximum xor_sum
    
    for(int f=31;f>=0;f--){
        if(basis[f]==0)// can't be set
            continue;
        int rep=1<<f;
        if(xor_sum&rep)// already set
            continue;
        
        xor_sum^=basis[f];// to set this fth bit must take its base element
    }
    return xor_sum;
}
