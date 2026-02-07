/*
This code can be used to get the sum of the k smallest or k largest elements that you currently have

How?
on adding val add to low first if low.size()>k move the largest element of low to high
on removing val if val is in low remove from low and add smallest in high to low
    if in high just remove from high

*/

// Currently gives the sum of the k smallest elements
struct KSum {
    multiset<int> low, high;
    ll current_sum = 0;
    int k;

    KSum(int x){
        k=x;
    }

    void add(int val) {
        low.insert(val);
        current_sum += val;

        // If low exceeds size k, move the largest to high
        if (low.size() > k) {
            auto it = prev(low.end());
            current_sum -= *it;
            high.insert(*it);
            low.erase(it);
        }
    }

    void remove(int val) {
        auto it = low.find(val);
        if (it != low.end()) {
            current_sum -= *it;
            low.erase(it);
            // Refill low from high to keep size k
            if (!high.empty()) {
                auto hi_it = high.begin();
                current_sum += *hi_it;
                low.insert(*hi_it);
                high.erase(hi_it);
            }
        } else if(high.find(val)!=high.end()){
            high.erase(high.find(val));
        }
    }
};


-> https://leetcode.com/problems/divide-an-array-into-subarrays-with-minimum-cost-ii