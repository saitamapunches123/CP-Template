/*
When we pass pointer to a function if we pass it by value the pointer doesnt change  if will still point to same adress but if we change the value the pinter points to (obviously it will change).

If we pass it by reference than the pointer itself will change and also the value it points to. (if we change it)
*/

void change_ptr(int *&ptr){
  ptr=NULL;
}
void change(int *ptr){
  *ptr=10;
  ptr=NULL;
}
int main(){
  int x=5;
  int *ptr=&x;
  change(ptr);
  cout<<x<<endl; // 10
  cout<<*ptr<<endl; //10 ptr still points to x and x is changed to 10
  change_ptr(ptr);
  cout<<*ptr<<endl; //seg fault  ptr is now null as ptr was passed by reference
}