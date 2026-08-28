/*
  Gaussian Elimnnation is used to convert a matrix into row echelon form using Row operations(swap rows, multiply row with const, add row)
  GaussJordanElimination is extension of Gaussian Elimnation which converts matrix into Reduced row echelon form(every cell above and below leading 1 is 0)
  row echelon form: where all the rows with non-zero elements have leading 1 and all the rows below it have 0 in that column

  e.g [[0,1,2,3]
      [0,0,1,3]]

  How to convert matrix into Row-echolen form??

  focus on One's in each row multiply by const so we get a leading one.
  and using this one convert all cells in the columnt above and below it to 0.
  
*/
using matrix=vector<vector<ll>>;
int mod=1e9+7;
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
/* 
USE ONLY IF MOD IS PRIME
a^−1 MOD=a^(MOD−2) MOD
*/
ll mod_inv_fermat(ll x, ll mod) {
    return mod_exp(x, mod - 2, mod); // Only works if mod is prime
}
void GaussJordanElimination(matrix &mat){
    int n = mat.size();
    int m = mat[0].size();

    int row = 0;

    for(int col = 0; col < m && row < n; col++){

        int sel = row;

        while(sel < n && mat[sel][col] == 0)
            sel++;

        if(sel == n)
            continue;

        swap(mat[sel], mat[row]);

        ll inv = mod_inv_fermat(mat[row][col], mod);

        // Normalize pivot row
        for(int j = col; j < m; j++)
            mat[row][j] = mat[row][j] * inv % mod;

        // Eliminate this column from every other row
        for(int i = 0; i < n; i++){

            if(i == row)
                continue;

            ll factor = mat[i][col];

            if(factor == 0)
                continue;

            for(int j = col; j < m; j++){
                mat[i][j] = (mat[i][j] - factor * mat[row][j]) % mod;
                if(mat[i][j] < 0)
                    mat[i][j] += mod;
            }
        }

        row++;
    }
}