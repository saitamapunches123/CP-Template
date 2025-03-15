struct DSU {
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n);
        size.resize(n,1);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
    	if(parent[x]==x)
    		return x;
        return parent[x]=find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a!= b) {
            if (size[a] < size[b]) swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    }

    bool sameSet(int a, int b) {
        return find(a) == find(b);
    }
    int getsize(int a){
    	int pa=find(a);
    	return size[pa];
    }
};
