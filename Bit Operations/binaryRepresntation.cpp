vector<int> getBits(int num) {
    vector<int> bits(32, 0);
    for (int i=0;i<32;i++) {
        int rep=1<<i;
        if((num&rep)==rep)
        bits[i] = 1;
    }
    return bits;
}
int vectorToInt( vector<int>& bits) {
    int num = 0;
    for (int i = 0; i < 32; i++) {
        if(bits[i]==1){
            num=num|(1<<i);
        }
    }
    return num;
}

// LONG LONG version of the functions

vector<int> getBits(ll num) {
    vector<int> bits(64, 0);
    for (ll i=0;i<64;i++) {
        ll rep=1ll<<i;
        if((num&rep)==rep)
        bits[i] = 1;
    }
    return bits;
}
ll vectorToInt(vector<int>& bits) {
    ll num = 0;
    for (ll i = 0; i < 64; i++) {
        if(bits[i]==1){
            num=num|(1ll<<i);
        }
    }
    return num;
}