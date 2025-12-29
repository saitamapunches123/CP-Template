/*
Functional graphs are graphs where each node has exactly one outgoing edge.
Thus functional graphs are mostly represented as arrays where arr[i] represents the outgoing edge from node i.

Functional grpahs will always have cycles. as number of vertices =n and number of edges=n

To find the cycle in a functional graph we can use Floyd tortoise and hare algorithm.


Also as functional graphs have only 1 outgoing edge we can use BINARY LIFTING to find the nth node from a node in O(logn) time.
*/