#include <bits/stdc++.h>
using namespace std;

/**
 * @brief KSum data structure to maintain the sum of the K smallest/largest elements in a sliding window or dynamic set.
 * 
 * This implementation uses two multisets (low and high) to keep track of elements.
 * By default, this specific implementation maintains the K smallest elements in 'low'.
 * 
 * Time Complexity:
 * - add: O(log N)
 * - remove: O(log N)
 * 
 * Space Complexity: O(N)
 */

typedef long long ll;

struct KSum {
    multiset<int> low, high;
    ll current_sum = 0;
    int k;

    KSum(int x) {
        k = x;
    }

    /**
     * @brief Adds a value and maintains the sum of the k smallest elements.
     */
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

    /**
     * @brief Removes a value and ensures 'low' still contains k elements if possible.
     */
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
        } else if (high.find(val) != high.end()) {
            high.erase(high.find(val));
        }
    }

    /**
     * @brief Returns the sum of the k smallest elements.
     */
    ll get_sum() {
        return current_sum;
    }
};
