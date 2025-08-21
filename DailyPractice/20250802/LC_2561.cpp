#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        ll n = basket1.size();
        map<ll,ll> cntBasket1,cntBasket2;
        set<ll> allValues;     
        vector<ll> swapValues;  
        ll minValue=1e18;  
        for(ll i=0;i<n;i++){
            cntBasket1[basket1[i]]++;
            cntBasket2[basket2[i]]++;
            minValue=min(minValue,basket1[i]*1ll);
            minValue=min(minValue,basket2[i]*1ll);
            allValues.insert(basket1[i]);
            allValues.insert(basket2[i]);
        }

        for(auto value:allValues){
            ll diff = cntBasket1[value]-cntBasket2[value];
            ll total = cntBasket1[value]+cntBasket2[value];
            if(total%2){
                return -1;
            }

            if(abs(diff)>0){
                for(int i=0;i<abs(diff)/2;i++){
                    swapValues.push_back(value);
                }
            }
        }

        sort(swapValues.begin(),swapValues.end());

        ll sz=swapValues.size(),ret=0;
        for(int i=0;i<sz/2;i++){
            ret=ret+min(minValue*2,swapValues[i]);
        }

        return ret;

    }
};