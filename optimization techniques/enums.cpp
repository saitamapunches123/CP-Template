/* 
use enum when dealing with fixed states
for ex: mapping 0->north 1->south 2->west 3->east
better to do
*/
enum Directions {South,North,West,East}; //does the integer mapping intenally and faster than string comparison

Directions d=South;