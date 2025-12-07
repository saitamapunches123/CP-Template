priority_queue<int>pq;//max heap
for(auto x:arr){
    pq.push(x);
    if(pq.size()>2)
        pq.pop();
}
int min2=pq.top();pq.pop();
int min1=pq.top();
//use a pq to get the 2 min or 2 max values and pop whenever size>2 just like we do to get top k elements simpler to implement than maintaing 2 variables min1 and min2