#include <bits/stdc++.h> 


int findMinimumCoins(int amount) 
{
   vector<int> coins={1,2,5,10,20,50,100,500,1000};
    
    int coin=0;
    int i=8;
    while(amount>0 && i>=0){
        coin+=amount/coins[i];
        amount=amount%coins[i];
        i--;
    }
    return coin;
}
