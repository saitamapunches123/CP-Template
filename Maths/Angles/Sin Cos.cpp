M_PI // declared varialbe stores pi

// M_PI radians = 180 degree
ld deg_to_rad(ld deg) {
  return deg * (M_PI / 180.0L);
}

ld rad_to_deg(ld rad){
  return rad * (180.0L / M_PI);
}

cos(x);
sin(x);// returns value of sin(x) where x is in radians

acos(x);
asin(x);// returns value of sin-1(x) in radians i.e for what y sin(y)=x

//QUESTION:
https://leetcode.com/contest/weekly-contest-497/problems/angles-of-a-triangle
 