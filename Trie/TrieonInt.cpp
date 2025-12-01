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
	TrieNode* child[2]={NULL,NULL};
	int cnt=0;
	TrieNode* get_child(int idx){
		if(this->child[idx]==NULL){
			this->child[idx]=new TrieNode();
		}
		return this->child[idx];
	}
};
struct Trie{
	TrieNode* root=new TrieNode();
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
	int get_less(ll x){//get cnt of values in trie strictly less than x
			vector<int> bits=getBits(x);
			TrieNode* curr=root;
			int ans=0;
			for(auto y:bits){
					if(y==1){
						 TrieNode *child0=curr->get_child(0);
						 ans+=child0->cnt;
					}
					curr=curr->get_child(y);
		}
		return ans;
	}
	int get_cnt(){
		return root->cnt;
	}
};