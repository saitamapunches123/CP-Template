/*
Simmilar to Monotonic queue it also stores the indices of element in increasing or decreasing order.
Monotonic Queue is helpfull to find the manimum or minimum for subarrays
implemented using deque
the front of the deque has the index for the greatest element in the subarray ans the next has index of second smalles and so on

*/

// usefull for Sliding Window Maximum/Minimum	

deque<int> inc_q;//q.fornt() will have the biggest value;
int i=0,j=0,n=arr.size();
vector<int> ans(n-k+1);// to find the maximum element in all k sized subarrays.
while(i<=n-k){
    while(j<i+k){
        while(inc_q.size()>0 and arr[j]>arr[inc_q.back()]){//push the value as far up as you can in queue
            inc_q.pop_back();// as there is an index in subbarray after it with bigger value thus this index can never be answer anyomore
        }
        inc_q.push_back(j);
        j++;
    }
    ans[i]=arr[inc_q.front()];
    if(inc_q.front()==i){//if the front is not in range for nex sub array pop it
        inc_q.pop_front();
    }
    i++;
}