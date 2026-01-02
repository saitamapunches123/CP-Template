/*
Pointers let us build data structures whose elements are not stored contiguously in memory, and they also enable O(1) insertion 

However, we can achieve the same flexibility without using raw pointers by representing links with array indices.
This approach removes pointer overhead,thus is generally faster though the implementation becomes less intuitive
*/
// for Binary Tree instead of
Struct Node{
  int val=0;
  Node* left=NULL;
  Node* right=NULL;
};
Node *root=new Node();

// we can do
struct Node{
  int val=0;
  int left=-1; //index of left child
  int right=-1; //index of right child
};
vector<Node> tree;
int root=0; //index of root

