for(auto x:arr){
    pq.push(x);
    if(pq.size()>2)
        pq.pop();
}
//use a pq to get the 2 minn