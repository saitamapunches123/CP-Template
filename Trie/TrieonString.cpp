struct TrieNode{
	TrieNode* child[26];
	int cnt;
    int ans;
	TrieNode(){
		for(int c=0;c<26;c++)
            child[c]=NULL;
		cnt=0; //number of string begininng with this 
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
    	void insert(string &s){
    		TrieNode* curr=root;
    		for(auto y:s)
    		{
                int idx=y-'a';
    			curr->cnt+=1;
    			curr=curr->get_child(idx);
    		}
    		curr->cnt+=1;
    	}
    	void remove(string &s){
    		TrieNode* curr=root;
    		for(auto y:s)
    		{
                int idx=y-'a';
    			curr->cnt-=1;
    			curr=curr->get_child(idx);
    		}
    		curr->cnt-=1;
    	}
    };