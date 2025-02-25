/*
let 2 players play a game with perfect information and 1 winner and other looser
For ex:- ther are n coins both player takes turns taking 1,3,4 coins the player who takes the last coin wins or player who cant take a coin looses
Tell for n coins who will win

coins-> 0  1  2  3  4  5  6  7  8  9 ......
W/L  -> L  W  L  W  W  W  W  L  W  W 

as from n we can go to n-1,n-3,n-4 if any one of these thre is a loosing position player 2 will loose thus 1 will winn
If all next positions  are winning than its a loosing position.

GAME OF NIM:

Game of nim is an extention of the game above and its result can be used to solve many games
In game on nim ther are n stack of coins. Both player takes turn to take positive number of coins>0 from any stack. Player who cant make a move looses
DECIDE WHO WINS if you know the number of coins in each stack?

ANSWER: if    x1^x2^x3^x4.....^xn = 0 (LOOSING)
        else  x1^x2^x3^x4.....^xn!= 0 (WINNING)
    
    Why this works? let (x1,x2,x3.....xn) be the current state
    if its loosing that is xorsum=0 ( all columns have number of set bits even ) any change to state(x1,x2,x3,....xi-k,,,xn ) will lead to xorsum!=0 ( as atlease one column will have odd set bits ).
    thus from LOOSING all next states are wining as it should be.

    Simmillary if at WINNING that is xorsum!=0 we can transition one of the xi to xi-k so that all columns have number of set bits even (by choosing the left most column with odd set bits).
    THUS we can always go from WINNING to LOOSING as it should be.
*/

bool nim(vector<int> & state){
    int xorsum=0;
    for(auto x:state)
    xorsum=xorsum^x;
    if(xorsum!=0);
    return true; // WINNING
    else
    return false; //LOOSING
}