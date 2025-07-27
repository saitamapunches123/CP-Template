/*

(a+b) xor c != a xor c + b xor c
thus if you have to do this do it bit wise for each bit individually

NOTE (2^30)>1e9

Distributive Laws

PS: NO bitwise operation is distributive over arithmetic and vice versa

1) AND distributes over OR and XOR
    x&(y|z)=(x&y)|(x&z)
    x&(y^z)=(x&y)^(x&z)
2) OR distributes over AND
    x|(y&z)=(x|y)&(x|z)
3)  XOR doesnt distribute over anyting


representing xor using and 

a^b=(a&^b)+(^a&b)

P.S: x=(x&y)+(x&^y) // this is not due to distributive property(doest exist) but only for this case
using this a+a^b=a+(a&^b)+(^a&b)=(a&b)+(a&^b)+(a&^b)+(^a&b)=b+2*(a&^b)
*/