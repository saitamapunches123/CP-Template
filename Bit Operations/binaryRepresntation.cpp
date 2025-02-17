vector<int> getBits(int num) {
    vector<int> bits(32, 0); // Initialize a vector of size 32 with 0
    for (int i = 31; i >= 0; i--) {
        bits[i] = (num & 1); // Get the least significant bit
        num >>= 1;          // Right shift the number
    }
    return bits;
}
int vectorToInt( vector<int>& bits) {
    int num = 0;
    for (int i = 0; i < 32; i++) {
        num = (num << 1) | bits[i]; // Left shift and add the current bit
    }
    return num;
}