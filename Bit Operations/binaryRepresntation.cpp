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