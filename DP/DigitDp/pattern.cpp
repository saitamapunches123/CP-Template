/*
SUM of digits from 0 to 1e9 can be upto 90 (999999999)
PRODUCT of digits from 0 to 1e9 can be upto 9^9

but distinct values of product of digits is only 3026 (YOU CAN WRITE A SMALL CODE TO CHECK THIS)
so memo on the product as arguemnt is possible.
this is because products like 121=11x11 is not possible
*/

//NEED TO ALSO HANDLE LEADING ZERO CONDITION as leading zeros are not a part of numbers

/*
PS: a simpler but less way to memo this could be convering all the params into 1 string.
*/
unordered_map<string,int> dp;
string get_key(int i,int sum,int prod,int f){
    return to_string(i)+"-"+to_string(sum)+"-"+to_string(prod)+"-"+to_string(f);
}


// digit DP pattern update based on use case
map<int,int> dp[10][90][2];
// f is that till now the digits chossen are same as that of s
int recur(string &s,int i,int sum,int prod,bool f){
    if(dp[i][sum][f].find(prod)!=dp[i][sum][f].end())
        return dp[i][sum][f][prod];
    if(i==s.size()){
        if(sum>0 and prod%sum==0)
            return dp[i][sum][f][prod]=1;
        return dp[i][sum][f][prod]=0;
    }
    int max_dig=9;
    if(f)
        max_dig=s[i]-'0';
    int ans=0;
    for(int dig=0;dig<=max_dig;dig++){
        int nsum=dig+sum;
        int nprod=prod;
        if(nsum!=0)
            nprod*=dig;    
        bool nf=false;
        if(f and dig==s[i]-'0')
            nf=true;
        ans+=recur(s,i+1,nsum,nprod,nf);
    }
    return dp[i][sum][f][prod]=ans;
}
int beautifulNumbers(int l, int r) {
    string sl=to_string(l-1),sr=to_string(r);
    int ans2=recur(sr,0,0,1,true);
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 90; j++) {
            for (int k = 0; k < 2; k++) {
                    dp[i][j][k].clear();
            }
        }
    }
    int ans1=recur(sl,0,0,1,true);
    return ans2-ans1;
}