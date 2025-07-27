/*
For Subarray remove from start or end continously
For Subsequence can remove any but remmaining elements in same order
For Subset can remove any and remaing elements in any order
*/

/*
use struct over a vector
struct Node {
        int r, c;
        int energy;
        int mask;
    };

as struct Node has a fixed size known at compile time

vector<int> is a dynamically sized container. Even if you only push 5 integers, the vector internally manages dynamic memory, allocates space, stores size, capacity, pointers, etc.
This overhead makes each vector<int> heavier in memory and slower to copy.

and always use .assign() over .resize() as reize acts weird when vector size> resize size
*/
