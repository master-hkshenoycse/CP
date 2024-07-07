#include<bits/stdc++.h>
using namespace std;
#define ll  long long
class Solution {
public:
    long long maximumPoints(vector<int>& enemyEnergies, int currentEnergy) {
        ll ans=0,n=enemyEnergies.size();
        ll sum=currentEnergy,mi=1e9;
        
        for(auto e:enemyEnergies){
            sum=sum+e;
            mi=min(mi,e*1ll);
        }

        if(currentEnergy<mi){
            return 0;
        }

        sum-=mi;
        return sum/mi;
    }
};