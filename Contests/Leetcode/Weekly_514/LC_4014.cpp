#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.begin(),prices.end());
        sort(discounts.begin(),discounts.end());
        double ret=0;

        while(prices.size()>0){
            double p=prices.back();
            prices.pop_back();

            double d=0.00;
            if(discounts.size()>0){
                d=(1.00*discounts.back())/100;
                discounts.pop_back();
            }

            d=1.00-d;
            ret=ret+d*p;

        }

        return ret;
    }
};