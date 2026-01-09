# GCD PROPERTIES — Cheat Sheet

gcd -> greatest coomon divisor of x and y

REMEMEBR: if d is a common divisor of x and y d is a common divisor of ax+by:
ax+by(mod d)= a *x(mod d)+b*y(mod d) = a*0+b*0=0

| Formula | Proof | 
|------------|--------------------------|
| gcd(x,y,z)=gcd(gcd(x,y),z) | intutive |
| gcd(x,y) >= gcd(x,y,z) | gcd is a decreasing function |
| gcd(x,y)<=min(x,y) | intutive |
| gcd(x,y) = gcd(x,y-x) | eucledian algo | 
| gcd(a1,a2,a3,...) = gcd(a1,a2-a1,a3,a4,....) | from above |


gcd(a1,a2,a3,...) = gcd(gcd(a1,a2),a3,...) = gcd(gcd(a1,a2-a1),a3,...) =gcd(a1,a2-a1,a3,...)

gcd(x,y)<=min(x,y)

---

