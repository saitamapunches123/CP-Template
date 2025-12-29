auto find_cycle=[&](int start)->tuple<vector<int>,vector<int>>{
  int slow=start,fast=start;
  do {
      slow = a[slow];
      fast = a[a[fast]];
  } while (slow != fast);

  slow = start;
  while (slow != fast) {
      slow = a[slow];
      fast = a[fast];
  }
  int entry = slow; // Entry point of the cycle
  int curr = start;
  while(vis[curr]==false){
    vis[curr]=true;
    curr=a[curr];
  }
  vector<int> branch_element,loop_elements;
  curr=start;
  while(curr!=entry){
    branch_element.push_back(curr);
    curr=a[curr];
  }
  do{
    loop_elements.push_back(curr);
    curr=a[curr];
  }while(curr!=entry);
  return {branch_element,loop_elements};
};