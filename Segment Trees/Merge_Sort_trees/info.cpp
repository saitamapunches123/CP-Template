/*
Merge sort trees are usefull when we need to process queries on the sorted form of subarray for example: [l,r,x] find the number of elements in the subarray [l,r] which are greater than x  OR find the lower bound of x in the subarray [l,r]


PS: Merge sort trees are not effecient and are slower than segment trees so dont use until and unless need to and n and q are a bit small(around 1e4)

TC: (n+q)log^2(n) // nlogn for building the tree and qlog^2(n) for querying

Here for each node we store the sorted form of the subarray i.e the sorted form of [ss,se]

Will this not be n^2 space???
NO as in Segmemt Tree each element is in log n segment so each element will be stored logn times and n element so nlogn


There are 2 version of merge sort trees

1) Static Merge sort trees : Here the array values dont change i.e no update queries thus we can use vector to store the sorted form of the subarray in static merge sort trees we can find number of elements greater than x in the subarray [l,r] in logn time using binary search lower_bound of x in  [l,r] and so on

2) Dynamic Merge sort trees : Here the array values can change i.e there are update queries thus we need to use multiset to store the sorted form of the subarray and in update we need to erase the old value and insert the new value in all log n segments the element is in

In Dynamic Merge sort trees finding number of elements greater than x in the subarray [l,r] is hard as distance() is a linerar function in multiset or we can use pbds indexed set (TODO STUDY indexed sets), but finding lower_bound and upper_bound can be done
*/



/*
Whats the best solution for [l,r,x] find the number of elements in the subarray [l,r] which are greater than x

it is not merge sort trees if all the querry and array is static it is sort the query and use segment treee on indexe i.e when processing the query [l,r,x] have only element arr[i]>x set as 1 and get sum of [l,r] in segment tree. NOW TC: nlogn + qlogn
*/