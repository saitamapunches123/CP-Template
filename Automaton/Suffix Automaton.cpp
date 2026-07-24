// guide https://codeforces.com/blog/entry/20861

// USEFULL FOR MOST SUBSTRING/SUBARRAY PROBLEMS
//FOR STRINGS
struct State {
    int len = 0;               // longest substring length in this state
    int link = -1;             // suffix link if u is the smallest substring in node. link links it to the node with longest proper suffix of u.
    map<char,int> next;        // transitions
};
/*
    node u has substring of len[link[u]]+1 to len[u]

    
    For any state:
    
    there is exactly ONE substring of each length in that state.
    
*/
struct SAM {

    vector<State> st;
    vector<bool> is_terminal;
    int last;

    SAM(string s) {
        // root state
        st.push_back(State());

        last = 0;

        for(char c : s)
            extend(c);
        generate_terminals();
    }

    void extend(char c) {

        // create new state
        int cur = st.size();

        st.push_back(State());

        st[cur].len = st[last].len + 1;

        int p = last;

        // add transitions that don't exist
        while(p != -1 && !st[p].next.count(c)) { // keep going till the transitions for c exists

            st[p].next[c] = cur;

            p = st[p].link;
        }

        // reached imaginary parent of root
        if(p == -1) {

            st[cur].link = 0;
        }
        else {

            int q = st[p].next[c];

            // good case
            if(st[p].len + 1 == st[q].len) {

                st[cur].link = q;
            }
            else {

                // create clone
                int clone = st.size();

                st.push_back(st[q]);

                st[clone].len = st[p].len + 1;

                // redirect transitions
                while(p != -1 && st[p].next[c] == q) {

                    st[p].next[c] = clone;

                    p = st[p].link;
                }

                st[q].link = clone;

                st[cur].link = clone;
            }
        }

        last = cur;
    }

    void generate_terminals(){
        int n=st.size();
        is_terminal.assign(n,false);
        int p = last;
        while(p > 0) {
            is_terminal[p]=true;
            p = st[p].link;
        }
    }

    bool check_substring(string &s){
        int curr=0,n=s.size();
        for(auto ch:s){
            if(st[curr].next.find(ch)==st[curr].next.end())
                return false;
            curr=st[curr].next[ch];
        }
        return true;
    }

    bool check_suffix(string &s){
        int curr=0,n=s.size();
        for(auto ch:s){
            if(st[curr].next.find(ch)==st[curr].next.end())
                return false;
            curr=st[curr].next[ch];
        }
        return is_terminal[curr];
    }
};

/*
PROBLEMS:
1) Number of distinct substrings?
    Number of total parths in the automaton
    Can be counted for each node as for u->v

Thus total distinct substrings 

∑(len[v]−len[link[v]]) for all v ∈ states

*/



class Solution {
public:
    struct State {
        int link = -1;
        int len = 0;
        int occ = 0; // number of occurences of the subarray
        map<int,int> next;
    };

    struct SAM {

        vector<State> st;
        int last;

        SAM(vector<int>&a) {
            int n=a.size();
            st.reserve(2 * n + 5);

            st.push_back(State());
            last = 0;
            build(a);
        }

        void extend(int c) {

            int cur = st.size();
            st.push_back(State());

            st[cur].len = st[last].len + 1;
            st[cur].occ = 1;

            int p = last;

            while(p != -1 && !st[p].next.count(c)) {
                st[p].next[c] = cur;
                p = st[p].link;
            }

            if(p == -1) {
                st[cur].link = 0;
            }
            else {

                int q = st[p].next[c];

                if(st[p].len + 1 == st[q].len) {
                    st[cur].link = q;
                }
                else {

                    int clone = st.size();

                    st.push_back(st[q]);

                    st[clone].len = st[p].len + 1;

                    // clone does not represent new occurrence
                    st[clone].occ = 0;

                    while(p != -1 && st[p].next[c] == q) {
                        st[p].next[c] = clone;
                        p = st[p].link;
                    }

                    st[q].link = st[cur].link = clone;
                }
            }

            last = cur;
        }

        void build(vector<int> &a) {

            for(int x : a)
                extend(x);

            // propagate occurrence counts

            vector<int> order(st.size());

            iota(order.begin(), order.end(), 0);

            sort(order.begin(), order.end(),
                 [&](int u, int v) {
                     return st[u].len > st[v].len;
                 });

            for(int v : order) {
                if(st[v].link != -1)
                    st[st[v].link].occ += st[v].occ; // number of occurence of x  has to have all the occurences of y+x (as this has x also in it)
            }
        }
    };
   
};