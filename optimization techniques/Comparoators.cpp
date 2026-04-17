// For Sort

sort(v.begin(), v.end(), [](int a, int b) {
    return a > b; // the biggest value will come first the sorting follows the order of the comparator
});


// For Priority Queue/Map/Set
auto cmp = [](int a, int b) {
    return a > b;
};

set<int, decltype(cmp)> s(cmp); // For set and map it follows the order of the comparator thus here both in descending order
map<int, int, decltype(cmp)> mp(cmp);
// For set/map/sort cmp(a,b) means Should a come before b??


priority_queue<int, vector<int>, decltype(cmp)> pq(cmp); // For priority queue it follows the REVERSE order of the comparator thus asscending order 
// For Priority queu cmp(a,b) means is a less priority than b here if a>b  then a is less priority than b thus a will come after b