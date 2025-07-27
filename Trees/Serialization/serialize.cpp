/*
serialization is used to represent the tree nodes structure
representing all the nodes and nodes of. nodes. as a string
*/
string serialize(TrieNode *curr){// serialization of u wih c1,c2,c3 as childs=> c1(serialize(c1))+c2(serialize(c2))+c3(serialize(c3))... doesnt have u only tells if theer exists a same tree or not thus used here
    vector<string> parts;
    for(auto [key,child]:curr->children){
        string part=child->s+"("+serialize(child)+")";
        parts.push_back(part);
    }
    sort(parts.begin(),parts.end());//to make serailzation sort proof i.e making x()y() and y()x() same
    string ans="";
    for(auto x:parts)
        ans+=x;
    // cout<<curr->s<<" "<<ans<<endl;
    mp[ans].push_back(curr);
    return ans;
}
