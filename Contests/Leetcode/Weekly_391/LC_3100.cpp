
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int emptyBottles=0,drink=0;
        while(numBottles>0 or emptyBottles>=numExchange){
            if(emptyBottles>=numExchange){
                emptyBottles-=numExchange;
                numExchange++;
                numBottles++;
            }
            drink+=numBottles;
            emptyBottles+=numBottles;
            numBottles=0;
        }

        return drink;
    }
};