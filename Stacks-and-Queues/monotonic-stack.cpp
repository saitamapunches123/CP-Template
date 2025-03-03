/*
Monotonic stack is helpfull when we need to get the next greater/ next smaller
in this the direction of traversal and the direction of next greater element is same
*/


stack<int> st; // Monotonic stack (stores indices)
for (int i = 0; i < n; i++) {
    while (!st.empty() && nums[st.top()] < nums[i]) {
        st.pop();
    }
    st.push(i); 
}