vector<int> getBits(ll num) {
    vector<int> bits(32, 0); // Initialize a vector of size 32 with 0
    for (int i = 31; i >= 0; i--) {
        bits[i] = (num & 1); // Get the least significant bit
        num >>= 1;          // Right shift the number
    }
    return bits;
}
ll vectorToInt(vector<int>& bits) {
    ll num = 0;
    for (int i = 0; i < 32; i++) {
        num = (num << 1) | bits[i]; // Left shift and add the current bit
    }
    return num;
}
struct TrieNode{
	TrieNode* child[2];
	int cnt;
	TrieNode(){
		child[0]=NULL;
		child[1]=NULL;
		cnt=0;
	}
	TrieNode* get_child(int idx){
		if(this->child[idx]==NULL){
			this->child[idx]=new TrieNode();
		}
		return this->child[idx];
	}
};
struct Trie{
	TrieNode* root;
	Trie(){
		root=new TrieNode();
	}
	void insert(ll x){
		vector<int> bits=getBits(x);
		TrieNode* curr=root;
		for(auto y:bits)
		{
			curr->cnt+=1;
			curr=curr->get_child(y);
		}
		curr->cnt+=1;
	}
	void remove(ll x){
		vector<int> bits=getBits(x);
		TrieNode* curr=root;
		for(auto y:bits)
		{
			curr->cnt-=1;
			curr=curr->get_child(y);
		}
		curr->cnt-=1;
	}
	int get_cnt(){
		return root->cnt;
	}
};