/*
Let there only be a 1 pile game, that is only 1 stack of coins and number of coins be n
NOW its simple if n=0 (LOOSING) else n>0 (WINNING) as player 1 can take all the coins in 1 go and win.
this can be represented as a grundy value or nimber
So:

Each nimber 0,3,5,...k  represent a 1 pile game with that many coins.
thus only nimber=0 is loosing 

HOW IS THIS USE FULL

SPARGE GRUNDY THEOREM:
nimber(s)=mex(nimber(r1),nimber(r2),.....nimber(ri)) Where r1,r2,r3, are all the next states of s

and this make sense as for 1 pile and can take 1,3,4 coins:
nimber(0)=mex()=0       loosing
nimber(1)=mex(0)=1      winning
nimber(2)=mex(1)=0      loosing
nimber(3)=mex(0,0)=1    winning
nimber(4)=mex(0,1,0)=1  winning
and so on...


MULTIPLE PILE: 
We can combine multiple nimber values That is we can devide our game into multiple sub-games
calculate the nimber for each sub-game state and combine it
as

nimber([p1,p2,p3,....])=nimber(p1)^nimber(p2)^nimber(p3)..... //xor sum of each individual nimber value

*/


int compute_nimber_state(vector<int>& nimbers,vector<int>& state){
    int n=state.size();
    int xor_val=0;
    for(int i=0;i<n;i++)
    {
      int x=state[i];
      xor_val=(xor_val^nimbers[x]);
    }
    // if(xor_val==0){
    //   cout<<"L";
    // }else{
    //   cout<<"W";
    // }
    return xor_val;
}

vector<int> get_nimber(int max_coins,vector<int>& s) //s all state transitions allowed
{
    vector<int> nimbers(max_coins+1); //as nimber[0]=0
    for(int coin=1;coin<=max_coins;coin++){
        set<int> reachable_nimber;// to compute mex val
        for(auto x:s){
            int rest_coin=coin-x;
            if(rest_coin>=0){
                reachable_nimber.insert(nimbers[rest_coin]);//all the nimber values reachable
            }
        }
        for(int mex=0;mex<=max_coins;mex++){ //mex of them
          if(reachable_nimber.find(mex)==reachable_nimber.end()){
            nimbers[coin]=mex;
            break;
          }
        }
        // cout<<coin<<" "<<nimbers[coin]<<endl;
    }
    return nimbers;
}