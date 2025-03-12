/*
Inclusion exlusion principle is used to caluclate the size/no of elements in union of n sets
It states that:

n(A1UA2UA3UA4U....An)=n(A1)+n(A2)+n(A3)+.....-n(A1∩A2)-n(A1∩A3)-n(A1∩A3)-....+n(A1∩A2∩A3) and so on.

   |⋃(i=1 to n) A_i| = ∑(i=1 to n) |A_i| 
                      - ∑(1 ≤ i < j ≤ n) |A_i ∩ A_j| 
                      + ∑(1 ≤ i < j < k ≤ n) |A_i ∩ A_j ∩ A_k| 
                      - ... 
                      + (-1)^(n-1) |A_1 ∩ ... ∩ A_n


*/


//FOR EXAMPLE:

int sub_sets=1<<m;
int shared=0;
for(int mask=1;mask<sub_sets;mask++){
    int y=0;
    for(int j=0;j<m;j++){
        if((mask&(1<<j))>0){
            y=y|(1<<bits[j]);
        }
    }
    int p=__builtin_popcount(mask); //gets number of set bits in it or here the number of sets whose intersection this is
    if(p%2) //add if odd
    shared+=mp[y];
    else //subtract if even
    shared-=mp[y];
}
