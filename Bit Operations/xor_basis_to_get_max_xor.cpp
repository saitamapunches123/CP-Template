
/*
This algorithm is usefull whenever we need to consider
all the xor-sums of the numbers in all possible subsets of the array

GIST of algorithm:
for the giver array find xor_basis
and than using the xor_basis and GREEDY right to left in binary i.e 2^i > 2^(i-1)+2^(i-2)+...
find the xor_value you need to take to set the right most possible bit
*/


// TC: O(n*b)
vector<int> get_xor_basis(vector<int> &arr){
    // basis is the minimal set of xor values(b1,b2,b3,...) such that the xor sum of sub sequence of basis can give me all values in arr
    // to get basis we will have each f(b)-> the last bit set in b to be unique for all values in basis 
    //P.S: for some question might need the change definetion of f(b)

    vector<int> basis(32);//basis[i]-> which element in basis has i as f value
    int sz=0;//sz of basis
    for(auto x:arr){
        for(int f=31;f>=0;f--){
            int rep=1<<f;
            if((rep&x)==0) continue; //dont need this bit
            if(basis[f]==0){// no element in basis has the i value
                basis[f]=x;// add x to basis
                sz++;
                break;
                }else{
                    x=x^basis[f];// as need this bit to be set in x
                }
            }
        }
    return basis;
}

// to get max xor_sum of sub sequence

ll xor_sum=0;
//using greedy to get the maximum xor_sum
for(int f=31;f>=0;f--){
    if(basis[f]==0)// cant be set
        continue;
    int rep=1<<f;
    if(xor_sum&rep)// already set
        continue;
    xor_sum^=basis[f];// to set this fth bit must take its base element
}